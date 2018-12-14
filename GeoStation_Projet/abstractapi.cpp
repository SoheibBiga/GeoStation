#include "abstractapi.h"

AbstractApi::AbstractApi(QObject *parent) : QObject(parent)
{

}

AbstractApi::AbstractApi(QObject *parent,int myId) : QObject(parent), Id(myId)
{

}
