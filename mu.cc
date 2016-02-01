#include <gtkmm.h>
#include <iostream>
using namespace std;

class Win : public Gtk::Window
{
public:
	Win() {
		add(b);
		b.signal_clicked().connect(sigc::mem_fun(*this, &Win::on_click));
		show_all_children();
	}
	~Win() {
		delete w;
	}
protected:
	Gtk::Button b;
	Win *w;
	void on_click() {
		w = new Win();
		cout << "inside" << endl;
		w->signal_hide().connect(sigc::mem_fun(*this, &Win::on_close));
	}
	void on_close() {
		delete w;
	}
};

int main() {
	auto app = Gtk::Application::create();
	Win win;
	return app->run(win);
}
