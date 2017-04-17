#include <QTextStream>

void decoder(QTextStream& out, QString path)
{
    out << "Decoding started" << endl;
    out << "Path to file is:" << " " << path << endl;
}
