#include "texteditcommand.h"
#include <QPlainTextEdit>


void TextEditCommand::redo()
{
    if (editType == InsertText)
    {
        textEdit->setPlainText(newText);
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(position);
        textEdit->setTextCursor(cursor);
    }
    else if (editType == ReMoveText)
    {
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(anchor);
        cursor.setPosition(position, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
        textEdit->setTextCursor(cursor);
    }
}

void TextEditCommand::undo()
{
    if (editType == InsertText)
    {
        textEdit->setPlainText(newText);
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(position);
        textEdit->setTextCursor(cursor);
    }
    else if (editType == ReMoveText)
    {
        QTextCursor cursor = textEdit->textCursor();
        cursor.setPosition(anchor);
        cursor.insertText(newText);
        textEdit->setTextCursor(cursor);
    }
}
