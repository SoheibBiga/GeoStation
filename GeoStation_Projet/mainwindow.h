#ifndef			MAINWINDOW_H_
# define		MAINWINDOW_H_

# include <QStackedWidget>
# include <QWidget>
# include <QTimer>
# include "ordonnanceur.h"
# include "awidget.h"
# include "mozaic.h"

class MainWindow : public QWidget
{
		Q_OBJECT

		QStackedWidget*		widgets_;
		ordonnanceur*     ordonnanceur_;
		Mozaic*						mozaic_;
		QTimer*						timer_;

		MainWindow(MainWindow const& other);
		MainWindow&			operator=(MainWindow const& other);

		void				initMozaic();
		void				initWidgets();

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		bool				init();
		bool				run();
		bool				end();
};

#endif // MAINWINDOW_H_
