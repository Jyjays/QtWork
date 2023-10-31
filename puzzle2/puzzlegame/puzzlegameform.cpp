#include "puzzlegameform.h"

puzzleGameForm::puzzleGameForm(QWidget *parent)
    : QWidget{parent}
{

}
void puzzleGameForm::_init(int cols, int rows, QPixmap puzzleImage)
{
    this->cols = cols;
    this->rows = rows;
    this->puzzleImage = puzzleImage;
    locations.resize(2*rows*cols);

    initializePuzzle();
    shufflePuzzle();
    // 在这里可以使用这些值做一些操作
}

void puzzleGameForm::initializePuzzle() {
    pieceWidth = puzzleImage.width() / cols;
    pieceHeight = puzzleImage.height() / rows;
    //locations.resize(rows * cols);
    setFixedSize(pieceWidth * cols, pieceHeight * rows);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = row * cols + col;
            locations[index] = QPoint(col * pieceWidth, row * pieceHeight);
        }
    }
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = row * cols + col;
            QLabel *pieceLabel = createPieceLabel(index);
            setInitialPosition(pieceLabel, col * pieceWidth, row * pieceHeight);
        }
    }
    windowWidth = pieceWidth * cols ;
    windowHeight = pieceHeight * rows ;
}

QLabel * puzzleGameForm::createPieceLabel(int index) {
    QLabel *pieceLabel = new QLabel(this);
    //pieceLabel->setProperty("index", index);
    pieceLabel->setPixmap(getPuzzlePiece(index));
    pieceLabel->setGeometry(locations[index].x(), locations[index].y(), pieceWidth, pieceHeight);
    pieceLabel->setAcceptDrops(true);
    pieceLabel->installEventFilter(this);
    pieceLabel->show();
    return pieceLabel;
}
QPixmap puzzleGameForm::getPuzzlePiece(int index) {
    int row = index / cols;
    int col = index % cols;
    return puzzleImage.copy(col * pieceWidth, row * pieceHeight, pieceWidth, pieceHeight);
}

void puzzleGameForm::setInitialPosition(QLabel *label, int x, int y) {
    pointLabelPairs.append(QPair<QPoint, QLabel*>(QPoint(x,y), label));
    correctPairs.insert(label,QPoint(x,y));
}


void puzzleGameForm::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void puzzleGameForm::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QLabel *label = qobject_cast<QLabel*>(childAt(event->pos()));
        if (label) {
            draggedLabel = label;
            offset = event->pos() - label->pos();
            offPoint = label->pos(); // 记录被拖离的拼图块的位置
            getCorrectPoint(offPoint);
        }
    }


}

void puzzleGameForm::mouseMoveEvent(QMouseEvent *event) {
    if (draggedLabel && (event->buttons() & Qt::LeftButton)) {
        draggedLabel->move(event->pos() - offset);
    }


}
void puzzleGameForm::mouseReleaseEvent(QMouseEvent *event) {
    if (draggedLabel) {
        QPoint currentPos = draggedLabel->pos();

        // 使用getCorrectPoint找到最近的位置
        getCorrectPoint(currentPos);

        swapPieces(draggedLabel,currentPos);

        draggedLabel = nullptr;

        if(moveCorrect()){
            QMessageBox::information(this, "Congratulations", "复原成功!");
            //stackedWidget->setCurrentWidget(0);
        }
    }
}

void puzzleGameForm::getCorrectPoint(QPoint &point) {
    int minDistance = std::numeric_limits<int>::max();
    QPoint nearestPoint;

    for (const QPoint &location : locations) {
        int distance = calculateDistance(point, location);

        if (distance < minDistance) {
            minDistance = distance;
            nearestPoint = location;
        }
    }
    point = nearestPoint;
}

void puzzleGameForm::swapPieces(QLabel* dragged, QPoint point) {
    QPoint currentPos = point;
    getCorrectPoint(currentPos);

    QPair<QPoint, QLabel*> *draggedPair = nullptr;
    QPair<QPoint, QLabel*> *targetPair = nullptr;

    for (QPair<QPoint, QLabel*> &pair : pointLabelPairs) {
        if (pair.second == dragged) {
            draggedPair = &pair;
        } else if (pair.first == currentPos) {
            targetPair = &pair;
        }
    }
    if (draggedPair->first == currentPos){
        draggedPair ->second->move(currentPos);
    }

    if (draggedPair && targetPair) {
        // 交换 QLabel 和 QPoint
        QPoint tempPoint = draggedPair->first;
        QLabel *tempLabel = targetPair->second;

        draggedPair->first = targetPair->first;
        draggedPair->second = dragged;

        targetPair->first = tempPoint;
        targetPair->second = tempLabel;

        // 移动 QLabel
        draggedPair->second->move(draggedPair->first);
        targetPair->second->move(targetPair->first);
    }
}



int puzzleGameForm::calculateDistance(const QPoint &point1, const QPoint &point2) {
    return qAbs(point1.x() - point2.x()) + qAbs(point1.y() - point2.y());
}


void puzzleGameForm::shufflePuzzle() {
    // 使用随机算法打乱拼图块的位置
    std::random_device rd;
    std::mt19937 gen(rd());  // 随机数生成器
    std::uniform_int_distribution<int> dis(0, pointLabelPairs.size() - 1);  // 均匀分布

    std::shuffle(pointLabelPairs.begin(), pointLabelPairs.end(), gen);

    // 重新设置拼图块的位置
    for (int i = 0; i < pointLabelPairs.size(); i++) {
        pointLabelPairs[i].first = locations[i];
        pointLabelPairs[i].second->move(locations[i]);
    }
}


bool puzzleGameForm::moveCorrect(){
    for (QPair<QPoint, QLabel*> &pair : pointLabelPairs) {
        if (pair.first!=correctPairs[pair.second]) {
            return false;
        }
    }
    return true;
}
