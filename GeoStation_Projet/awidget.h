#ifndefAWIDGET_HH_
# defineAWIDGET_HH_

# include <QWidget>

/*
**AWidget::mainLayout_ and AWidget::mozaicLayout_ to instanciate in the
** init() method of the derived class.
** AWidget::id_ is setted with currentId_ which is auto-increment
*/

class AWidget : public QWidget
{
  AWidget();
  AWidget(AWidget const& other);
  AWidget&operator=(AWidget const& other);
  
 protected:
  int			id_;
  QLayout*		mainLayout_;
  QLayout*		mozaicLayout_;

  static int		currentId_;

 public:
  explicit AWidget(QWidget* parent = 0);
  virtual ~AWidget();

  virtual int		getId() const;
  virtual QLayout*	getMainLayout() const;
  virtual QLayout*	getMozaicLayout() const;
  virtual bool		contentMap() const = 0;
  virtual bool		hasMozaicLayout() const = 0;
  virtual bool		refresh() const = 0;
  virtual bool		init() = 0;
  virtual bool		run() = 0;
  virtual bool		end() = 0;
  virtual void		addWidget(QWidget* widget) = 0;
};

#endif // AWIDGET_HH_
