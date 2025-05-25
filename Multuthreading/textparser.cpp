#include "textparser.h"

TextParser::TextParser(QThread *parent)
    : QThread{parent}
{}


void TextParser::run()
{
    if (m_text.isEmpty() || m_charset.isEmpty()) {
        return;
    }

    int textSize = m_text.size();

    for (int index = 0; index < textSize; index++) {
        if (m_charset.indexOf(m_text[index].toLower()) == -1) {
            m_charsAmount++;
        }
        double currentProgress = (double)index / (double)textSize * 100;
        emit progress(currentProgress);
        emit currentIndex(index);
    }
    qDebug() << "Finished!";
    emit progress(100);
}
