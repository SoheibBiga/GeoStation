#ifndef			MAINWINDOW_H_
# define		MAINWINDOW_H_

# include <QStackedWidget>
# include <QWidget>
# include <QTimer>
# include "mozaic.h"
# include "ordonnanceur.h"
# include <QStackedWidget>
# include "awidget.h"
# include "sncfwidget.h"
# include "satellitewidget.h"
# include "museeswidget.h"
# include "tableauwidget.h"
# include <QMap>
# include "evenementwidget.h"
# include <sncfapi.h>
# include "pharmaciewidget.h"

class MainWindow : public QWidget
{
		Q_OBJECT

        QStackedWidget*		widgets_;
        ordonnanceur*        ordonnanceur_;
        Mozaic*				mozaic_;
        QTimer*				timer_;

		MainWindow(MainWindow const& other);
		MainWindow&			operator=(MainWindow const& other);

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		bool				init();
		bool				run();
		bool				end();
};

#endif // MAINWINDOW_H_
