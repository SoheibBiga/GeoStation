#ifndef				AWIDGET_HH_
# define			AWIDGET_HH_

# include <QWidget>
# include "iwidget.h"

class AWidget : public QWidget
{
		static int					currentId_;

		AWidget();
		AWidget(AWidget const& other);
		AWidget&			operator=(AWidget const& other);

	protected:
		int									id_;
		QLayout*						mainLayout_;
		QLayout*						mozaicLayout_;

	public:

		explicit AWidget(QWidget* parent = 0);
		~AWidget();

//		virtual int					getId() const;
//		virtual QLayout*		getMainLayout() const;
//		virtual QLayout*		getMozaicLayout() const;
//		virtual bool				contentMap() const = 0;
//		virtual bool				hasMozaicLayout() const = 0;
//		virtual bool				refresh() const = 0;
//		virtual bool				init() = 0;
//		virtual bool				run() = 0;
//		virtual bool				end() = 0;

//public slots:
   // virtual void send_info(QMap<QString, QString> *map_formulaire) =0;
};

#endif // AWIDGET_HH
