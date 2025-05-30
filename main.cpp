#include <QGuiApplication>
#include "display_widget.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	rf::DisplayWidget w;
	w.show();
	return app.exec();
}
