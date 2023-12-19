#include "mainwindow.h"

#include <QApplication>

#include <QCoreApplication>
#include <QDebug>

// 自定义消息处理函数
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context);

    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", localMsg.constData());
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s\n", localMsg.constData());
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", localMsg.constData());
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", localMsg.constData());
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", localMsg.constData());
        QCoreApplication::exit(1); // 程序退出，可以根据需要修改退出码
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(customMessageHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
