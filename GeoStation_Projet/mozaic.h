#ifndef				MOZAIC_H_
# define			MOZAIC_H_

# include <QWidget>
# include <QHBoxLayout>
# include <QVBoxLayout>
# include "awidget.h"

class Mozaic : public AWidget
{
		Q_OBJECT

		QVBoxLayout*				hLayout_;
		QHBoxLayout*				vLayout1_;
		QHBoxLayout*				vLayout2_;

	public:
		explicit Mozaic(QWidget* parent = Q_NULLPTR);
		virtual ~Mozaic();


		virtual bool				contentMap() const;
		virtual bool				hasMainLayout() const;
		virtual bool				hasMozaicLayout() const;
		virtual bool				refresh();
		virtual bool				init();
		virtual bool				show();
		virtual bool				run();
		virtual bool				end();
		virtual void				addWidget(QWidget* widget);

	private slots:
    void receive_info(QMap<QString,QString>);
};

#endif // MOZAIC_H_
