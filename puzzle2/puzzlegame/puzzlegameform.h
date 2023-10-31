#ifndef PUZZLEGAMEFORM_H
#define PUZZLEGAMEFORM_H

#include "mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QVector>
#include <QList>
#include <QMap>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QMouseEvent>
#include <QMimeData>
#include <random>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QStringList>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStackedWidget>
#include <QFile>
#include <QFileDialog>
class puzzleGameForm : public QWidget
{
    Q_OBJECT
public:
    explicit puzzleGameForm(QWidget *parent = nullptr);
    //friend class MainWindow;
    void _init(int cols,int rows, QPixmap puzzleImage );
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

private:
    void initializePuzzle();
    QLabel *createPieceLabel(int index);
    void setInitialPosition(QLabel *label, int x, int y);
    void getCorrectPoint(QPoint &point);
    int calculateDistance(const QPoint &point1, const QPoint &point2);
    void swapPieces(QLabel* dragged,QPoint point);
    QPixmap getPuzzlePiece(int index);
    void shufflePuzzle();
    bool moveCorrect();



    QPixmap puzzleImage;
    QVector<QPoint> locations;
    //QMap<QPoint,QLabel*> LabelMap;
    QList<QPair<QPoint, QLabel*>> pointLabelPairs;
    QMap<QLabel*,QPoint> correctPairs;
    int cols;
    int rows;
    int pieceWidth;
    int pieceHeight;
    int windowWidth;
    int windowHeight;
    QLabel *draggedLabel;
    QPoint offset;
    QPoint offPoint;
    //QPoint currentPos;
    QTimer* timer;
};

#endif // PUZZLEGAMEFORM_H
