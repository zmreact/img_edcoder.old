#include <QTextStream>
#include <QImage>
#include <QImageReader>
#include <QColor>

bool readimageblock(QTextStream& out, QString path)
{
    QImage img(path);
    if (img.isNull()!=true)
    {
        out << "Width: " << img.width() << endl;
        out << "Height: " << img.height() << endl;
        out << "Depth: " << img.bitPlaneCount() << endl;
        out << "Bytes per line: " << img.bytesPerLine() << endl;
     } else return false;
}
