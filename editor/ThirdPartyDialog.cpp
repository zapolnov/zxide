#include "ThirdPartyDialog.h"
#include "ui_ThirdPartyDialog.h"

ThirdPartyDialog::ThirdPartyDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_ThirdPartyDialog)
{
    mUi->setupUi(this);

    mUi->textView->setHtml(QStringLiteral(
        "<html><body>"

        "<p>This program embeds FUSE (The Free Unix Spectrum Emulator):<br>"
        "<a href=\"http://fuse-emulator.sourceforge.net/\">http://fuse-emulator.sourceforge.net/</a><br>"
        "Copyright &copy; 1999-2018 Philip Kendall and others.<br>"
        "Licensed under the GNU General Public License.</p>"

        "<hr>"

        "<p>This program uses the Audio File library:<br>"
        "<a href=\"https://audiofile.68k.org/\">https://audiofile.68k.org/</a><br>"
        "Copyright &copy; 1998-2013, Michael Pruett.<br>"
        "Licensed under the GNU Lesser General Public License.</p>"

        "<hr>"

        "<p>This program uses bzip2:<br>"
        "<a href=\"https://sourceforge.net/projects/bzip2/\">https://sourceforge.net/projects/bzip2/</a><br>"
        "Copyright &copy; 1996-2019 Julian R Seward. All rights reserved.<br>"
        "Licensed under a BSD-like license.</p>"

        "<hr>"

        "<p>This program uses zlib:<br>"
        "<a href=\"https://www.zlib.net/\">https://www.zlib.net/</a><br>"
        "Copyright &copy; 1995-2017 Jean-loup Gailly and Mark Adler.</p>"

        "<hr>"

        "<p>This program uses &quot;Farm-Fresh Web Icons&quot; by FatCow:<br>"
        "<a href=\"http://www.fatcow.com/free-icons\">http://www.fatcow.com/free-icons</a></p>"

        "<hr>"

        "<p>This program uses Fugue Icons:<br>"
        "Copyright &copy; 2013 Yusuke Kamiyamane. All rights reserved.<br>"
        "Licensed under the Creative Commons Attribution 3.0 License.<br>"
        "<a href=\"https://p.yusukekamiyamane.com/\">https://p.yusukekamiyamane.com/</a></p>"

        "<hr>"

        "<p>This program uses Scintilla:<br>"
        "<a href=\"https://www.scintilla.org/\">https://www.scintilla.org/</a><br>"
        "Copyright &copy; 1998-2003 by Neil Hodgson. All Rights Reserved.<br>"
        "<br>"
        "Permission to use, copy, modify, and distribute this software and its<br>"
        "documentation for any purpose and without fee is hereby granted,<br>"
        "provided that the above copyright notice appear in all copies and that<br>"
        "both that copyright notice and this permission notice appear in<br>"
        "supporting documentation.<br>"
        "<br>"
        "NEIL HODGSON DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS<br>"
        "SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY<br>"
        "AND FITNESS, IN NO EVENT SHALL NEIL HODGSON BE LIABLE FOR ANY<br>"
        "SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES<br>"
        "WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,<br>"
        "WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER<br>"
        "TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE<br>"
        "OR PERFORMANCE OF THIS SOFTWARE.</p>"

        "</body></html>"
        ));
}

ThirdPartyDialog::~ThirdPartyDialog()
{
}
