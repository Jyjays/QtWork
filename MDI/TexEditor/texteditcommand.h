#ifndef TEXTEDITCOMMAND_H
#define TEXTEDITCOMMAND_H
#include <QUndoCommand>
#include <QTextDocument>
#include <QTextCursor>
#include <QPlainTextEdit>
enum EditType {
    InsertText,  // 表示插入文本操作
    DeleteText,  // 表示删除文本操作
    ReMoveText  // 表示替换文本操作，您可以根据需要扩展
};
class TextEditCommand : public QUndoCommand
{
public:
    TextEditCommand(QPlainTextEdit *textEdit, EditType editType, const QString &text, int anchor, int position)
        : textEdit(textEdit), editType(editType), newText(text), anchor(anchor), position(position)
    {
        if (editType == InsertText)
        {
            setText("Insert Text");
        }
        else if (editType == ReMoveText)
        {
            setText("Remove Text");
        }
    }


    void redo() override;
    void undo() override;

private:
    QPlainTextEdit *textEdit;
    EditType editType;
    QString newText;
    int anchor;
    int position;
};


#endif // TEXTEDITCOMMAND_H
