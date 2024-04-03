#ifndef CRANDOM_H
#define CRANDOM_H

#include <QObject>
#include <QStack>
#include <random>

class CRandom : public QObject
{
    Q_OBJECT
public:
    explicit CRandom(QObject *parent = nullptr);

    // Function to select a random movie from the stack
    QString selectRandomMovie(QStack<QString>& stack);

private:
    std::mt19937 generator;  // Standard mersenne_twister_engine seeded with rd()
};
