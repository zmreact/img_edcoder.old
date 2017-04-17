#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QStringList>
#include <stdio.h>
#include <QTextStream>

#include <encoder.h>
#include <decoder.h>

using namespace std;

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QCoreApplication ed(argc, argv);
    ed.setApplicationName("Image Encoder/Decoder");
    ed.setApplicationVersion("1.0");


    /* parser declaration */
    QCommandLineParser parser;
    QCommandLineOption encode(QStringList() << "e" << "encode",
            "Encode <image file to encode>",
            "string");
    QCommandLineOption decode(QStringList() << "d" << "decode",
            "Decode <image file to decode>",
            "code");
    QCommandLineOption help(QStringList() << "h" << "help",
            "Shows this help");
    parser.addOption(encode);
    parser.addOption(decode);
    parser.addOption(help);

    QStringList helptextQSL;
    helptextQSL << parser.helpText().split("\n");
    helptextQSL.removeFirst();
    helptextQSL.removeFirst();
    helptextQSL.removeLast();
    QString helptext = (QString) helptextQSL.join("\n");


    parser.process(ed);


    /* welcome message */
    QStringList WelcomeMessageQSL;
    WelcomeMessageQSL << "Moscow Technical University of Communication and Informatics" << "\n" << "Department of multimedia networks and communication services" << "\n" << "Course work on MSKvSPD" << "\n" << "Student group: BSU1401" << "\n"
                      << "Developers:" << " " << "Denis Petuhov" << "," << "\n"
                      << "            " << "Korotygin Aleksandr" << "," << "\n"
                      << "            " << "Kaledina Anastasija" << "," << "\n"
                      << "            " << "Gubankova Ekaterina" << "." << "\n" << "\n"
                      << ed.applicationName() << "." << " " << "Version" << " " << ed.applicationVersion() << "\n" << "\n"
                      << "Usage:" << " " << argv[0] << " " << "[-e image file to encode] [-d image file to encode]" << "\n"
                      << "Supported file image formats: *.tif, *.tiff" << "\n" << "\n"
                      << helptext << "\n" "\n";
    QString WelcomeMessage = (QString) WelcomeMessageQSL.join("");
    out << WelcomeMessage;


    /* options switch */
    switch (parser.optionNames().isEmpty()) {
    case 1:
        break;
    case 0:
        if (parser.optionNames()[0] == QString("e")) {
            encoder(out, parser.value("e"));
        } else if (parser.optionNames()[0] == QString("d")) {
            decoder(out, parser.value("d"));
        } else if (parser.optionNames()[0] == QString("h")) {
            /* just nothing happens*/
        } else break;
    default:
        break;
    }


    return 0;
}

