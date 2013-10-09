; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define EXECNAME "leterrier-calculment"
#define ICONNAME "leterrier-calculment"
#define DIRNAME "calculmental"
#define APPNAME "Le Terrier d'AbulEdu - Calcul Mental"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{62974C8F-0013-4262-AF5E-7F46C992672E}
AppName={#APPNAME}
AppVersion=LAVERSION
AppPublisher=RyX�o SARL
AppPublisherURL=http://www.abuledu.org/leterrier/
AppSupportURL=http://www.abuledu.org/leterrier/
AppUpdatesURL=http://www.abuledu.org/leterrier/
DefaultDirName={pf}/AbulEdu/{#DIRNAME}
DefaultGroupName=Le Terrier d'AbulEdu
LicenseFile=../gpl-3.0.txt
OutputDir=.
OutputBaseFilename={#EXECNAME}-LAVERSION-setup
SetupIconFile={#EXECNAME}.ico
Compression=lzma
SolidCompression=yes
; WizardImageFile=imageWizard.bmp
SignTool=ryxeo /d $qPackage d'installation$q $f
SignedUninstaller=True
SignedUninstallerDir=.

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "french"; MessagesFile: "compiler:Languages/French.isl"

[Tasks]
; Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "../src/release/{#EXECNAME}.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "../debian/*.desktop"; DestDir: "{app}"; Flags: ignoreversion
Source: "../src/data/*"; DestDir: "{app}/data"; Flags: ignoreversion recursesubdirs createallsubdirs
; Source: "../src/exemples/*.abe"; DestDir: "{app}/data"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../src/conf/*"; DestDir: "{app}/conf"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../src/lang/*.qm"; DestDir: "{app}/lang"; Flags: ignoreversion
Source: "C:/code/qt-bin-package/*"; Excludes: "*.txt"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; opencv
; Source: "C:/code/opencv/build/x86/mingw/bin/*.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; pour alacarte > 1.0.8
Source: "../debian/*.desktop"; DestDir: "{win}/abuledu-alacarte/data/profile1.applications"; AfterInstall: UpdateDesktopPath; Flags: ignoreversion
Source: "../src/data/icones/{#EXECNAME}-128.png"; DestDir: "{app}"; Flags: ignoreversion
; pour picotts
; Source: "../src/lib/abuledupicottsv1/lang/*.*"; DestDir: "{app}/data/picotts"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
; Name: "{group}/{#APPNAME}"; Filename: "{app}/{#EXECNAME}.exe"; WorkingDir: "{app}"
; Name: "{commondesktop}/{#APPNAME}"; Filename: "{app}/{#EXECNAME}.exe"; Tasks: desktopicon; WorkingDir: "{app}"

[Run]
; Filename: "{app}/{#EXECNAME}.exe"; Description: "{cm:LaunchProgram,{#APPNAME}}"; Flags: nowait postinstall skipifsilent

[Code]
procedure UpdateDesktopPath();
var Strings : TArrayOfString;
begin
  SetArrayLength(Strings, 1);
  Strings[0] := 'X-Horizon-WindowsExecPath=' + ExpandConstant('{app}');
  SaveStringsToFile(ExpandConstant('{win}') + '/abuledu-alacarte/data/profile1.applications/{#EXECNAME}.desktop', Strings, True);
end;
