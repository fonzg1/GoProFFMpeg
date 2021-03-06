/****************************************************************************
**
** Namespace GoProApi generated by dumpcpp v5.11.0 using
** dumpcpp C:\Users\u1\Desktop\dlls\GoProApi.tlb
** from the type library C:\Users\u1\Desktop\dlls\GoProApi.tlb
**
****************************************************************************/

#ifndef GOPROAPI_H
#define GOPROAPI_H

#include <QObject>
#include <QMap>

class GoProApiQT : public QObject
{
    Q_OBJECT

public:
    explicit GoProApiQT(QObject *parent = nullptr);
    QString GetIPAdress() const { return "10.5.5.9"; }
    QString GetHTTPIPAdress() const { return "http://10.5.5.9"; }
    QString getSessionMAC() const { return m_sSessionMac; }
    bool isConnected() const { return m_bConnected; }

    enum HeroCommands
    {
        GpCommand,
        Shutter1,
        Shutter0,
        GpControl,
        GpControlStatus,
        Pair,
        GpMedialist,
        DeleteLast,
        SetVideoMode,
        EmptyCommand
    };

signals:
    void connectionChanged(bool isConnected);

public slots:
    bool Connect(int msTimeout=-1, bool showDialogs=true);
    void StartVideo();
    void StopVideo();
    bool LoadFromCamera(QString &outPath, const QString &destDir="", bool needRemoveSrc=false);
    bool CameraIsBusy();
    void DeleteLastMedia();

protected:
    QString Get(GoProApiQT::HeroCommands heroCommands, int msTimeout, const QString &arg="", bool showDialogs=true, const QString &fileName="");
    void FillHeroCommands();
    bool CheckConnection();

    bool m_bConnected;
    QString m_sSessionMac;
    QMap<int,QString> m_mpHeroCommands;
};

#endif

