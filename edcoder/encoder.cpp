#include <QTextStream>

void encoder(QTextStream& out, QString path)
{
    out << "Encoding started" << endl;
    out << "Path to file is:" << " " << path << endl;
}
