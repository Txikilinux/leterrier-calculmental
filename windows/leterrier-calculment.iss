; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{62974C8F-0013-4262-AF5E-7F46C992672E}
AppName=Calcul Mental
AppVersion=1.0.8
AppPublisher=RyX�o SARL
AppPublisherURL=http://www.abuledu.org/leterrier/
AppSupportURL=http://www.abuledu.org/leterrier/
AppUpdatesURL=http://www.abuledu.org/leterrier/
DefaultDirName={pf}\AbulEdu\Calcul Mental
DefaultGroupName=Le Terrier d'AbulEdu
LicenseFile=../gpl-2.0.txt
OutputDir=.
OutputBaseFilename=leterrier-calcul-mental-1.0.8-setup
Compression=lzma
SolidCompression=yes
SetupIconFile=icone.ico
WizardImageFile=imageWizard.bmp

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "../release\leterrier-calcul-mental.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "../data\*"; DestDir: "{app}\data"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\QtScript4.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\QtNetwork4.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\QtGUI4.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\QtCore4.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\QtXml4.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\mingwm10.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\bin\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\2010.05\qt\plugins\imageformats\*"; DestDir: "{app}\imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Calcul Mental"; Filename: "{app}\leterrier-calcul-mental.exe"; WorkingDir: "{app}"
Name: "{commondesktop}\Calcul Mental"; Filename: "{app}\leterrier-calcul-mental.exe"; WorkingDir: "{app}"; Tasks: desktopicon

[Run]
Filename: "{app}\leterrier-calcul-mental.exe"; Description: "{cm:LaunchProgram,Le Terrier d'AbulEdu}"; Flags: nowait postinstall skipifsilent

