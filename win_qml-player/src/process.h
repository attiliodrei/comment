#ifndef PROCESS_H
#define PROCESS_H

#include <QProcess>
#include <QObject>
#include <QDebug>
class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = 0);
    Q_INVOKABLE void start(const QString &program, const QString &arguments);
    Q_INVOKABLE void stop();

//    Q_INVOKABLE QByteArray readAll() ;


public slots:
 void process_started();

//private slots:
//    void onStarted();

private:
    QProcess *m_process;
};
#endif // PROCESS_H
