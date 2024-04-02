#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include <QStack>
#include <QString>

class CFantasyMovies : public QObject
{
    Q_OBJECT
public:
    explicit CFantasyMovies(QObject *parent = nullptr);

    // Set the stacks of movie titles
    void setStacks(const QStack<QString>& oddStack, const QStack<QString>& evenStack);

signals:
    // Signal emitted when a movie is selected
    void movieSelected(QString movieTitle);

public slots:
    // Slot to select a movie based on the provided number
    void selectMovie(int number);

private:
    QStack<QString> stack_odd;
    QStack<QString> stack_even;
};

#endif // CFANTASYMOVIES_H
