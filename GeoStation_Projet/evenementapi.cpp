#include "evenementapi.h"


EvenementApi::EvenementApi(QObject *parent,int id): AbstractApi(parent,id)
{
  //manager
  manager = new QNetworkAccessManager (parent);
  m_event = new QNetworkAccessManager (parent);

}

EvenementApi::~EvenementApi()
{

}

void EvenementApi::display()
{

}


void EvenementApi::reponseRecue(QNetworkReply *reply)
{

}
