#include "CReadFile.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

CReadFile::CReadFile(QObject *parent) : QObject(parent) {
}


// Reads movie titles from 'input.txt', distributing them into odd and even stacks
void CReadFile::readFile() {
    QFile file("input.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open input.txt for reading.";
        return;
    }

    QTextStream in(&file);
    int lineNumber = 1;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (lineNumber % 2 == 0) {
            stack_even.push(line);
        } else {
            stack_odd.push(line);
        }
        lineNumber++;
    }
    file.close();
}
