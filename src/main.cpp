#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CReadFile.h"
#include "CFantasyMovies.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Create application engine
    QQmlApplicationEngine engine;

    // Read input file and populate stacks
    CReadFile readFile;
    readFile.readFile(); // Populate the stacks on startup

    // Set stacks in CFantasyMovies
    CFantasyMovies fantasyMovies;
    fantasyMovies.setStacks(readFile.getOddStack(), readFile.getEvenStack());

    // Expose the CFantasyMovies object to QML
    engine.rootContext()->setContextProperty("fantasyMovies", &fantasyMovies);

    // Load GUI QML file
    engine.load(QUrl(QStringLiteral("qrc:/EvenOrOdd.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
