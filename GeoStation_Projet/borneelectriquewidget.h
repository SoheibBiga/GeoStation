#ifndef			BORNEELECTRIQUEWIDGET_H
# define		BORNEELECTRIQUEWIDGET_H

# include "awidget.h"
# include "borneelectriquemozaicwidget.h"

class BorneElectriqueWidget : public AWidget
{

	public:
		BorneElectriqueWidget(QWidget* parent = 0);

		bool				contentMap() const;
		bool				hasMozaicLayout() const;
		bool				refresh();
		bool				init();
		bool				run();
		bool				end();
		void				addWidget(QWidget* widget);

        borneelectriquemozaicwidget *borneelectrique_mozaic_widget;
signals:
    void send_info2(QMap<QString,QVariant>);
};

#endif // BORNEELECTRIQUEWIDGET_H
