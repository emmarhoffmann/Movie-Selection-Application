#include "CFantasyMovies.h"
#include "CRandom.h"

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) {
}

void CFantasyMovies::setStacks(const QStack<QString>& oddStack, const QStack<QString>& evenStack) {
    // Set the stacks of movie titles
    stack_odd = oddStack;
    stack_even = evenStack;
}

void CFantasyMovies::selectMovie(int number) {
    CRandom random;

    QString selectedMovie;
    // Check if the provided number is even or odd
    if (number % 2 == 0) {
        // If even, select a random movie from stack_even if not empty, else from stack_odd
        if (!stack_even.isEmpty()) {
            selectedMovie = random.selectRandomMovie(stack_even);
        } else if (!stack_odd.isEmpty()) {
            selectedMovie = random.selectRandomMovie(stack_odd);
        }
    } else {
        // If odd, select a random movie from stack_odd if not empty, else from stack_even
        if (!stack_odd.isEmpty()) {
            selectedMovie = random.selectRandomMovie(stack_odd);
        } else if (!stack_even.isEmpty()) {
            selectedMovie = random.selectRandomMovie(stack_even);
        }
    }

    // Emit the selected movie title or a message if no movies are available
    if (!selectedMovie.isEmpty()) {
        emit movieSelected(selectedMovie);
    } else {
        emit movieSelected("No more available films");
    }
}
