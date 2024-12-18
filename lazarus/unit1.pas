unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  database;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    procedure Button1Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var database:PDB;
    types: array[0..1] of  DB_TYPE;
    content: array[0..1] of integer;
    output: array[0..1] of integer;
begin
     types[0] := DB_INTEGER;
     database := create_database(1, 1, types);
     content[0] := 100;
     assign_row(database, 0, @content);
     get_row(database, 0, @output);
     Edit1.Text := inttostr(output[0]);
     delete_database(database);
end;

end.

