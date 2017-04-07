#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QStringList>
#include <stdio.h>
#include <QTextStream>

using namespace std;

void encoder();

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
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
    encode.~QCommandLineOption();
    decode.~QCommandLineOption();
    help.~QCommandLineOption();

    QStringList helptextQSL;
    helptextQSL << parser.helpText().split("\n");
    helptextQSL.removeFirst();
    helptextQSL.removeFirst();
    helptextQSL.removeLast();
    QString helptext = (QString) helptextQSL.join("\n");
    helptextQSL.~QList<QString>();

    parser.process(ed);



    /* welcome message */
    QStringList WelcomeMessageQSL;
    WelcomeMessageQSL << "Moscow Technical University of Communication and Informatics" << "\n" << "Department of multimedia networks and communication services" << "\n" << "Course work on MSKvSPD" << "\n" << "Student group: BSU1401" << "\n" << "Developers:" << " " << "Denis Petuhov" << "," << " " << "etc." << "\n" << "\n" << ed.applicationName() << "." << " " << "Version" << " " << ed.applicationVersion() << "\n" << "\n"
                      << "Usage:" << " " << argv[0] << " " << "[-e string] [-d code]" << "\n"
                      << helptext << "\n";
    QString WelcomeMessage = (QString) WelcomeMessageQSL.join("");
    WelcomeMessageQSL.~QList<QString>();



    /* options switch */
    switch (parser.optionNames().isEmpty()) {
    case 1:
        out << WelcomeMessage;
        break;
    case 0:
        if (parser.optionNames()[0] == QString("e")) {
            encoder();
        } else if (parser.optionNames()[0] == QString("d")) {
            out << endl << "Option -d is hit!" << endl;
        } else if (parser.optionNames()[0] == QString("h")) {
            out << WelcomeMessage;
        } else break;
    default:
        break;
    }



    return 0;
}

void encoder()
{
    QTextStream out(stdout);
    out << endl << "Option -e is hit!" << endl;
}
