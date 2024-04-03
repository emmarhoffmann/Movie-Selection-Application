#include "CRandom.h"
#include <random>
#include <QTime>

CRandom::CRandom(QObject *parent) : QObject(parent) {
    // Seed with a real random value
    std::random_device rd;
    generator.seed(rd());
}

QString CRandom::selectRandomMovie(QStack<QString>& stack) {
    if (stack.isEmpty()) {
        return QString();
    }

    // Generate a random index within the stack size
    std::uniform_int_distribution<int> distribution(0, stack.size() - 1);
    int randomIndex = distribution(generator);
    QStack<QString> tempStack;
    QString selectedMovie;

    // Move  items above the random index to a temporary stack
    while (stack.size() > randomIndex + 1) {
        tempStack.push(stack.pop());
    }

    // The top of the stack is the randomly selected movie
    selectedMovie = stack.pop();

    // Move items back from the temporary stack to the original stack
    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop());
    }

    return selectedMovie;
}
