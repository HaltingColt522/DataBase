
unit database;
{$link database.o}
{$link access.o}
{$link dynamic.o}

{$ifdef WINDOWS}
{$linklib libmsvcrt.a}
{$linklib libmingw32.a}
{$linklib libgcc.a}
{$linklib libmingwex.a}
{$else} // Linux
{$linklib libc} // or try {$linklib c}
{$endif}

interface

{
  Automatically converted by H2Pas 1.0.0 from database.h
  The following command line parameters were used:
    -e
    -d
    database.h
}

{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}

type
  DB_TYPE =  Longint;
    Const
      INTEGER = 0;
      BOOLEAN = 1;
      STRINGG = 2;

type
  ROW = record
      ptr : pointer;
      _type : DB_TYPE;
        size : size_t;
      end;

    DB = record
        colums_c : dword;
        rows_c : dword;
        entries : array of ROW;
      end;
  PDB = ^DB;

  function create_database(rows:dword; colums:dword; types:array of DB_TYPE):PDB;cdecl;external;

  procedure delete_database(db:PDB);cdecl;external;

  {rows start at 0 - (index at array) }
  {TODO: MAYBE use user defined index instead }
  procedure assign_row(db:PDB; row:dword; content:pointer);cdecl;external;

  procedure clear_row(db:PDB; row:dword);cdecl;external;

  procedure get_row(db:PDB; row:dword; output:pointer);cdecl;external;

  procedure delete_row(db:PDB; row:dword);cdecl;external;

  function add_row(db:PDB; row:dword; _type:DB_TYPE):PDB;cdecl;external;

  {pass the row behind which you want the new row }

implementation


end.
