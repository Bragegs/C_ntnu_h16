#include <gtkmm.h>
#include <iostream>

using namespace std;


class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry first_name_entry;
  Gtk::Entry last_name_entry;
  Gtk::Button button;
  Gtk::Label first_name_label;
  Gtk::Label last_name_label;
  Gtk::Label label;

  Window() {

    this->set_title("Øving 4");
    
    button.set_label("Combine names");
    button.set_sensitive(false);
    
    first_name_label.set_text("First name");
    vbox.pack_start(first_name_label);
    vbox.pack_start(first_name_entry);  
    
    last_name_label.set_text("Last name");
    vbox.pack_start(last_name_label);
    vbox.pack_start(last_name_entry);
    
    vbox.pack_start(button); 
    vbox.pack_start(label);  

    add(vbox);  
    show_all(); 

    
    auto should_button_be_sensitive = [this] () -> bool { return (!first_name_entry.get_text().empty() && !last_name_entry.get_text().empty());};
    // ville prøve anonyme funksjoner i stedet for en if-setning, men:
    // det ble kanskje en kostbar anonym funksjon, da den må kopieres for hver gang? Hvilken av metodene nedenfor er best mtp capture list?


    first_name_entry.signal_changed().connect([this, should_button_be_sensitive]() {
      button.set_sensitive(should_button_be_sensitive());

    });
    
    last_name_entry.signal_changed().connect([=]() {
      button.set_sensitive(should_button_be_sensitive());
    });
    
    button.signal_clicked().connect([this]() {
      stringstream ss;
      ss << "Combined name: " << first_name_entry.get_text() << " " << last_name_entry.get_text();   
      label.set_text(ss.str());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}