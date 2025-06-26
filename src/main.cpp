/*
 *      Nana C++ Library - Creator
 *      Author: besh81
 */
#include <nana/gui.hpp>
#ifdef NANA_WINDOWS
#include <windows.h>
#endif //NANA_WINDOWS
#include "config.h"
#include "imagemanager.h"
#include "filemanager.h"
#include "inifile.h"
#include "creator.h"

static std::string BASE[] = {
   "/usr/share/nana-creator",
   "/usr/local/nana-creator",
   "/usr/local/share/nana-creator",
   "./wdir"
};

imagemanager	g_img_mgr;
filemanager	g_file_mgr;	// manage absolute and relative path
inifile		g_inifile;


#ifdef NANA_WINDOWS
	#ifdef __RELEASE
	int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
	#else
	int main()
	#endif //__RELEASE
#else
	int main()
#endif //NANA_WINDOWS
{
	// init ctrls images
	g_img_mgr.add(CTRL_FIELD, "icons/horizontal_layout.png");
	g_img_mgr.add(CTRL_GRID, "icons/grid_layout.png");
	g_img_mgr.add(CTRL_SPLITTERBAR, "icons/splitter.png");
	g_img_mgr.add(CTRL_BUTTON, "icons/button.png");
	g_img_mgr.add(CTRL_LABEL, "icons/label.png");
	g_img_mgr.add(CTRL_TEXTBOX, "icons/textbox.png");
	g_img_mgr.add(CTRL_LISTBOX, "icons/listbox.png");
	g_img_mgr.add(CTRL_PANEL, "icons/panel.png");
	g_img_mgr.add(CTRL_COMBOX, "icons/combox.png");
	g_img_mgr.add(CTRL_SPINBOX, "icons/spinbox.png");
	g_img_mgr.add(CTRL_CHECKBOX, "icons/checkbox.png");
	g_img_mgr.add(CTRL_DATECHOOSER, "icons/datechooser.png");
	g_img_mgr.add(CTRL_TOOLBAR, "icons/toolbar.png");
	g_img_mgr.add(CTRL_FORM, "icons/form.png");
	g_img_mgr.add(CTRL_CATEGORIZE, "icons/categorize.png");
	g_img_mgr.add(CTRL_GROUP, "icons/group.png");
	g_img_mgr.add(CTRL_MENUBAR, "icons/menubar.png");
	g_img_mgr.add(CTRL_PICTURE, "icons/picture.png");
	g_img_mgr.add(CTRL_PROGRESS, "icons/progress.png");
	g_img_mgr.add(CTRL_SLIDER, "icons/slider.png");
	g_img_mgr.add(CTRL_TABBAR, "icons/tabbar.png");
	g_img_mgr.add(CTRL_TREEBOX, "icons/treebox.png");
	g_img_mgr.add(CTRL_NOTEBOOK, "icons/notebook.png");
	g_img_mgr.add(CTRL_PAGE, "icons/page.png");
	g_img_mgr.add(CTRL_CUSTOM, "icons/custom.png");
        // Icon
	g_img_mgr.add(CTRL_CREATOR, "icons/creator.ico");
        // GUI menubar
        g_img_mgr.add(GUI_NEWPRJ, "icons/new_prj.png");
        g_img_mgr.add(GUI_LOADPRJ, "icons/load_prj.png");
        g_img_mgr.add(GUI_SAVE, "icons/save.png");
        g_img_mgr.add(GUI_SAVEAS, "icons/save_as.png");
        g_img_mgr.add(GUI_OUTPUT, "icons/output.png");
        g_img_mgr.add(GUI_UP, "icons/up.png");
        g_img_mgr.add(GUI_DOWN, "icons/down.png");
        g_img_mgr.add(GUI_DELETE, "icons/delete.png");
        g_img_mgr.add(GUI_CUT, "icons/cut.png");
        g_img_mgr.add(GUI_COPY, "icons/copy.png");
        g_img_mgr.add(GUI_PASTE, "icons/paste.png");
        g_img_mgr.add(GUI_INFO, "icons/info.png");
        g_img_mgr.add(GUI_ITEM_ADD, "icons/item_add.png");
        g_img_mgr.add(GUI_SEP_ADD, "icons/sep_add.png");
        g_img_mgr.add(GUI_NC, "icons/nc.png");

        for (int i=0; i < 4; ++i) {
		std::string test_base = BASE[i];
		if(file_exists(test_base + "/" + g_img_mgr.path(CTRL_CREATOR))) {
			g_img_mgr.sethome(test_base + "/");
                        break;
		}
	}
	creator fm(0, nana::size{ 1200, 700 });
	fm.icon(nana::paint::image(g_img_mgr.path(CTRL_CREATOR)));

	fm.show();
	nana::exec();
}
