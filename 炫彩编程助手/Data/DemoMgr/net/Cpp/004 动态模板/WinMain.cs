﻿using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices;
using XCGUI;


class CWindow
{
    unsafe public void Create()
    {
        xc.XInitXCGUI("");
        int hWindow = xc.XWnd_Create(0, 0, 500, 300, "xcgui", 0, 15);

        int hElePanel = xc.XC_LoadLayout("..\\..\\Pane.xml",0);
        xc.XWnd_AddEle(hWindow, hElePanel);

        xc.XWnd_ShowWindow(hWindow, 5);
        xc.XRunXCGUI();
        xc.XExitXCGUI();
    }
}

namespace Project1
{
    class RunMain
    {
        static void Main()
        {
            CWindow pWindow = new CWindow();
            pWindow.Create();
        }
        
    }
}
