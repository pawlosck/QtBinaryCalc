#ifndef DEBUG_H
#define DEBUG_H
#include <qdebug.h>
#include <QTime>







//DEBUGMODE - wyswietla/nie wyswietla wszystkie mozliwe informacje we wszystkich mozliwych czesciach programu
#define DEBUGMODE 0


#if DEBUGMODE == 0 //wylaczone wszelkie komunikaty diagnostyczne

#define SHOWLINE
#define SHOWVALUE(nazwa,wartosc)
#define SHOWONLYVALUE(wartosc)
#define SHOW(nazwa)
#define SHOWINOUT(nazwa)



#elif DEBUGMODE == 1 //wlaczone wszystkie mozliwe komunikaty diagnostyczne

#define SHOWLINE qDebug()<<"Time: "<<QTime::currentTime().toString("HH:mm:ss:zzz")<<" File: "<<__FILE__<<" Line: "<<__LINE__
#define SHOWVALUE(nazwa,wartosc) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]          [ "<<wartosc<<" ]"
#define SHOWONLYVALUE(wartosc) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#wartosc" ]          [ "<<wartosc<<" ]"
#define SHOW(nazwa) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]"
#define SHOWINOUT(nazwa) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]"


#elif DEBUGMODE == 2 //pozwala wlaczyc indywidualnie ustawienia, a nie wszystko wlaczone, lub wylaczone

#define SHOWLINE qDebug()<<"Time: "<<QTime::currentTime().toString("HH:mm:ss:zzz")<<" File: "<<__FILE__<<" Line: "<<__LINE__
//#define SHOWLINE

#define SHOWVALUE(nazwa,wartosc) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]          [ "<<wartosc<<" ]"
//#define SHOWVALUE(nazwa,wartosc)

#define SHOWONLYVALUE(wartosc) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#wartosc" ]          [ "<<wartosc<<" ]"
#define SHOWONLYVALUE(wartosc)

//#define SHOW(nazwa) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]"
#define SHOW(nazwa)

//#define SHOWINOUT(nazwa) qDebug()<<__FILE__<<"("<<__LINE__<<")     ["<<#nazwa" ]"
#define SHOWINOUT(nazwa)

#endif







#endif // DEBUG_H




//#define SHOWLINE qDebug(" File: %s - Line: %d",__FILE__, __LINE__)
