#ifndef			BORNEELECTRIQUEWIDGET_H
# define		BORNEELECTRIQUEWIDGET_H

# include "awidget.h"

class BorneElectriqueWidget : public AWidget
{

	public:
		BorneElectriqueWidget();
		bool				contentMap() const;
		bool				hasMozaicLayout() const;
		bool				refresh();
		bool				init();
		bool				run();
		bool				end();
		void				addWidget(QWidget* widget);
};

#endif // BORNEELECTRIQUEWIDGET_H
