#include "eventapi.h"





EventApi::EvenementApi(QObject *parent,int id): AbstractApi(parent,id)
{
  //manager
  manager = new QNetworkAccessManager (parent);
  m_event = new QNetworkAccessManager (parent);

  connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseRecue(QNetworkReply *)));
  connect(m_event, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseRecue(QNetworkReply *)));

}

EventApi::~EventApi()
{

}

void EventApi::display()
{

}




void EventApi::reponseRecue(QNetworkReply *reply)
{

}
