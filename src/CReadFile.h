#ifndef CREADFILE_H
#define CREADFILE_H

#include <QObject>
#include <QString>
#include <QStack>

// Manages reading and organizing movie titles from a text file
class CReadFile : public QObject
{
    Q_OBJECT
public:
    explicit CReadFile(QObject *parent = nullptr);
    void readFile(); // Reads and sorts titles into odd and even stacks

    QStack<QString> getOddStack() const { return stack_odd; }
    QStack<QString> getEvenStack() const { return stack_even; }

private:
    QStack<QString> stack_odd;
    QStack<QString> stack_even;
};

#endif // CREADFILE_H

