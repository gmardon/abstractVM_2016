#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QWidget>
#include <QVBoxLayout>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <QLabel>
#include <QHBoxLayout>

class   stackWidget : public QWidget
{
    stackWidget(QWidget *parent = 0);
};

class   codeWidget : public QWidget
{
public:
    codeWidget(std::string &cmd, QWidget *parent = 0);
    void    getCodeLines(std::string);
    void    fillText();

    QPushButton *quit;
    QGridLayout *grid;
    QHBoxLayout *layout;
    QLabel  *code;
    std::vector<std::string> codeLines;
};

void    codeWidget::getCodeLines(std::string cmd)
{
    std::string delimiter = "\n";
    size_t  pos = 0;
    std::string token;
    auto start = 0U;
    auto end = cmd.find(delimiter);

    while (end != std::string::npos)
    {
        token =  cmd.substr(start, end - start);
        codeLines.push_back(token);
        //std::cout << ">" << token << std::endl;
        start = end + delimiter.length();
        end = cmd.find(delimiter, start);
     }

    std::cout << cmd.substr(start, end);
}

codeWidget::codeWidget(std::string &cmd, QWidget *parent) : QWidget(parent)
{
    quit = new QPushButton(tr("Quit"), this);
    grid = new QGridLayout;
    layout = new QHBoxLayout;
    code = new QLabel(parent);
    std::vector<std::string>::iterator it;

    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    code->setText(QString::fromStdString(cmd));
    code->setStyleSheet("QLabel { background-color : white; color : green   ; }");
    getCodeLines(cmd);
    for (it = codeLines.begin() ; it < codeLines.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    layout->addWidget(quit);
    layout->addWidget(code);
    setLayout(layout);
}



std::string getFile(char *file)
{
    std::ifstream fileContent;
    std::stringstream fileContentSS;
    std::string        contentString;

    fileContent.open(file);
    if (!(fileContent.is_open()))
    {
        std::cout << "[!] Error while opening file...\n" << std::endl;
        exit(84);
    }
    fileContentSS << fileContent.rdbuf();
    contentString = fileContentSS.str();

    return (contentString);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::string  cmd;

    cmd = getFile(argv[1]);
    codeWidget  cWidget(cmd);

    //std::cout << "[*] File content :" << std::endl << cmd << std::endl;
    cWidget.show();

    return a.exec();
}

