#ifndef PROCESS_H
#define PROCESS_H

#include <QProcess>
#include <QObject>
class Process : public QObject {
    Q_OBJECT
public:
    explicit Process(QObject *parent = 0);
    Q_INVOKABLE void start(const QString &program, const QVariantList &arguments);

private:
    QProcess *m_process;
};
#endif // PROCESS_H
