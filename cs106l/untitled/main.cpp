 #include <iostream>
#include "SimpleGraph.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <QFile>
#include <QTextStream>
#include <ctime>

using std::cout;	using std::endl;
using std::string;  using std::cin; using std::cout;
using std::ifstream;


const double kPi =  3.14159265358979323;
const int k = 10;                           //作用力系数
const int MAXN = 1e7;
int nodeNum;
SimpleGraph graph;
std::pair<double,double> delta[MAXN];

void Welcome();
void getGraph(const QString &filePath);
void init_node(SimpleGraph &graph);
void Force_directed();
void repulse();
void attract();
void Move();
double sqrNode(Node &node1,Node &node2);

// Main method
int main() {
    Welcome();

    getGraph(":/res/5clique");
    InitGraphVisualizer(graph);
    DrawGraph(graph);
    Force_directed();

    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;

}
void getGraph(const QString &filePath){

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open input file";
    } else {
        QTextStream stream(&file);

        // 读取节点数量
        QString str = stream.readLine();
        nodeNum = str.toInt();

        // 读取边信息
        while (!stream.atEnd()) {
            str = stream.readLine();
            QStringList parts = str.split(" ", Qt::SkipEmptyParts);
            if (parts.size() == 2) {
                size_t u = parts[0].toULongLong();
                size_t v = parts[1].toULongLong();
                graph.edges.push_back({u, v});
            } else {
                qWarning() << "Invalid edge format in line:" << str;
            }
        }
    }

    file.close();
    init_node(graph);

}
void init_node(SimpleGraph &graph){

    for(int i=0;i<nodeNum;i++){
        graph.nodes.push_back(Node{std::cos(2*kPi*i/nodeNum),std::sin(2*kPi*i/nodeNum)});
    }
}
void Force_directed(){
    // time_t startTime = time(NULL);
    // int count = 1e5;
    while(true){
        std::memset(delta ,0 ,sizeof(delta));
        repulse();
        attract();
        Move();
        DrawGraph(graph);
        //--count;
    }


    //double elapsedTime = difftime(time(NULL), startTime);

    //qDebug()<< elapsedTime;
}

void repulse(){
    for(int i=0;i=nodeNum;i++){
        for(int j = i+1;j<=nodeNum;j++){
            auto node1 = graph.nodes[i];
            auto node2 = graph.nodes[j];
            double distance = sqrNode(node1,node2);
            double force = k/std::sqrt(distance);
            double theta = std::atan2(node1.x,node2.y);
            delta[i].first-=force*std::cos(theta);
            delta[j].first+=force*std::cos(theta);
            delta[i].second-=force*std::sin(theta);
            delta[i].second+=force*std::sin(theta);

        }
    }
}

void attract(){
    for(auto edge: graph.edges){
        auto node1 = graph.nodes[edge.start];
        auto node2 = graph.nodes[edge.end];
        double distance = sqrNode(node1,node2);
        double force = k/std::sqrt(distance);
        double theta = std::atan2(node1.x,node2.y);
        delta[edge.start].first-=force*std::cos(theta);
        delta[edge.end].first+=force*std::cos(theta);

    }
}

void Move(){
    for(int i=0;i<=nodeNum;i++){
        graph.nodes[i].x += delta[i].first;
        graph.nodes[i].y += delta[i].second;
    }
}
double sqrNode(Node &node1,Node &node0){
    return std::pow(node1.x-node0.x,2)+std::pow(node1.y-node0.y,2);
}

