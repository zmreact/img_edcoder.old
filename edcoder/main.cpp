#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QStringList>
#include <stdio.h>
#include <QTextStream>

using namespace std;
QTextStream out(stdout);

int main(int argc, char *argv[]);
void encoder();
void decoder();

int main(int argc, char *argv[])
{
    QCoreApplication ed(argc, argv);
    ed.setApplicationName("Encoder/Decoder");
    ed.setApplicationVersion("1.0");


    /* parser declaration */
    QCommandLineParser parser;
    QCommandLineOption encode(QStringList() << "e" << "encode",
            "Encode string <string>",
            "string");
    QCommandLineOption decode(QStringList() << "d" << "decode",
            "Decode binary code <code>",
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
    WelcomeMessageQSL << "Moscow Technical University of Communication and Informatics" << "\n" << "Department of multimedia networks and communication services" << "\n" << "Course work on MSKvSPD" << "\n" << "Student group: BSU1401" << "\n" << "Developers:" << " " << "Denis Petuhov" << "," << " " << "etc." << "\n" << "\n" << ed.applicationName() << "." << " " << "Version" << " " << ed.applicationVersion() << "\n" << "\n"
                      << "Usage:" << " " << argv[0] << " " << "[-e string] [-d code]" << "\n"
                      << helptext << "\n" "\n";
    QString WelcomeMessage = (QString) WelcomeMessageQSL.join("");
    out << WelcomeMessage;


    /* options switch */
    switch (parser.optionNames().isEmpty()) {
    case 1:
        break;
    case 0:
        if (parser.optionNames()[0] == QString("e")) {
            encoder();
        } else if (parser.optionNames()[0] == QString("d")) {
            decoder();
        } else if (parser.optionNames()[0] == QString("h")) {
            /* just nothing happens*/
        } else break;
    default:
        break;
    }


    return 0;
}

void encoder()
{
    out << "Option -e is hit!" << endl;
}

void decoder()
{
    out << "Option -d is hit!" << endl;
}
