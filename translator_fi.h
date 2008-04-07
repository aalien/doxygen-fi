/******************************************************************************
 *
 * 
 *
 * Copyright (C) 1997-2008 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */
/*
==================================================================================
Suomenkielinen k‰‰nnˆs:
Olli Korhonen      <olli.korhonen@ccc.fi>
Antti Laine        <antti.a.laine@tut.fi>
==================================================================================
1999/10/19
*  Alustava k‰‰nnˆs valmis.

*  Huom: Kaikille termeille on keksitty k‰‰nnˆsvastine, mik‰ ei ehk‰ ole 
         kaikissa tapauksissa hyv‰ ratkaisu, ja parempikin termi voi 
         olla vakiintuneessa k‰ytˆss‰.

* Teht‰v‰‰: 
        - Termien kokoaminen listaksi ja suomennosten j‰rkevyyden tarkastelu. (lista on jo melko kattava)
                Author          = Tekij‰
                Class           = Luokka
                Compound        = Kooste
                Data            = Data
                Documentation   = Dokumentaatio
                Defines         = M‰‰rittelyt
                Description     = Selite
                Detailed        = Yksityiskohtainen
                Diagram         = Kaavio
                Enum            = Enumeraatio / Luettelotyyppi
                Exceptions      = Poikkeukset
                File            = Tiedosto
                Friends         = Yst‰v‰t
                Functions       = Funktiot
                Hierarchical    = Hierarkinen
                Index           = Indeksi
                Inherits        = Perii
                Member          = J‰sen
                Module          = Moduli
                Namespace       = Nimiavaruus
                Parameters      = Parametrit
                Private         = Yksityinen
                Protected       = Suojattu
                Prototypes      = Prototyypit
                Public          = Julkinen
                Reference Manual= K‰sikirja
                Reimplemented   = Uudelleen toteutettu
                Related         = Liittyv‰
                Signals         = Signaalit
                Slots           = Vastineet
                Static          = Staattinen
                Struct          = Tietue
                Typedef         = Tyyppim‰‰rittely
                Union           = Yhdiste
                Variables       = Muuttujat
        - Taivutusmuotojen virheettˆmyyden tarkastelu prepositioiden korvauskohdissa.
        - Sanasta sanaan k‰‰nnˆskohtien mielekkyyden tarkastelu valmiista dokumentista.
        - umlaut vastineiden k‰yttˆ scandien kohdalla.

positiiviset kommentit otetaan ilolla vastaan.
===================================================================================
*/

#ifndef TRANSLATOR_FI_H
#define TRANSLATOR_FI_H

class TranslatorFinnish : public TranslatorEnglish
{
  public:
    /*! This method is used to generate a warning message to signal
     *  the user that the translation of his/her language of choice
     *  needs updating.
     */
    virtual QCString updateNeededMessage()
    {
      return "Warning: The Finnish translator is really obsolete.\n"
             "It was not updated since version 1.0.0.  As a result,\n"
             "some sentences may appear in English.\n\n";
    }
    
    // --- Language control methods -------------------
    
    /*! Used for identification of the language. The identification 
     * should not be translated. It should be replaced by the name 
     * of the language in English using lower-case characters only
     * (e.g. "czech", "japanese", "russian", etc.). It should be equal to 
     * the identification used in language.cpp.
     */
    QCString idLanguage()
    { return "finnish"; }

    /*! Used to get the LaTeX command(s) for the language support. 
     *  This method should return string with commands that switch
     *  LaTeX to the desired language.  For example 
     *  <pre>"\\usepackage[german]{babel}\n"
     *  </pre>
     *  or
     *  <pre>"\\usepackage{polski}\n"
     *  "\\usepackage[latin2]{inputenc}\n"
     *  "\\usepackage[T1]{fontenc}\n"
     *  </pre>
     * 
     * The English LaTeX does not use such commands.  Because of this
     * the empty string is returned in this implementation.
     */
    virtual QCString latexLanguageSupportCommand()
    {
      return "\\usepackage[finnish}{babel}"
             "\\usepackage[latin1]{inputenc}"
             "\\usepackage[T1]{fontenc}";
    }

    /*! return the language charset. This will be used for the HTML output */
    virtual QCString idLanguageCharset()
    {
      return "iso-8859-1";
    }

    // --- Language translation methods -------------------

    /*! used in the compound documentation before a list of related functions. */
    QCString trRelatedFunctions()
    { return "Liittyv‰t funktiot"; } // "Related Functions";

    /*! subscript for the related functions. */
    QCString trRelatedSubscript()
    { return "(Huomaa, ett‰ n‰m‰ eiv‰t ole j‰senfunktioita.)"; } // "(Note that these are not member functions.)"

    /*! header that is put before the detailed description of files, classes and namespaces. */
    QCString trDetailedDescription()
    { return "Yksityiskohtainen selite"; } // "Detailed Description"

    /*! header that is put before the list of typedefs. */
    QCString trMemberTypedefDocumentation()
      // header that is put before the list of typedefs.
    { return "J‰sentyyppim‰‰rittelyiden dokumentaatio"; } // "Member Typedef Documentation"

    /*! header that is put before the list of enumerations. */
    QCString trMemberEnumerationDocumentation()
    { return "J‰senenumeraatioiden dokumentaatio"; } // "Member Enumeration Documentation"

    /*! header that is put before the list of member functions. */
    QCString trMemberFunctionDocumentation()
    { return "J‰senfunktioiden dokumentaatio"; } // "Member Function Documentation"

    /*! header that is put before the list of member attributes. */
    virtual QCString trMemberDataDocumentation()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Kenttien dokumentaatio"; // "Field Documentation"; 
      }
      else
      {
        return "J‰sendatan dokumentaatio"; // "Member Data Documentation"
      }
    }

    /*! this is the text of a link put after brief descriptions. */
    QCString trMore()
    { return "Lis‰‰..."; } // "More..."

     /*! put in the class documentation */
    QCString trListOfAllMembers()
    { return "Lista kaikista j‰senist‰."; } // "List of all members."
    QCString trMemberList()

    /*! used as the title of the "list of all members" page of a class */
    { return "J‰senlista"; } // "Member List"

    /*! this is the first part of a sentence that is followed by a class name */
    QCString trThisIsTheListOfAllMembers()
    { return "T‰m‰ on lista kaikista j‰senist‰"; } // "This is the complete list of members for "

    /*! this is the remainder of the sentence after the class name */
    QCString trIncludingInheritedMembers()
    { return ", sis‰lt‰en kaikki perityt j‰senet."; } // ", including all inherited members."

    /*! this is put at the author sections at the bottom of man pages.
     *  parameter s is name of the project name.
     */
    QCString trGeneratedAutomatically(const char *s)
    { QCString result="Automaattisesti generoitu Doxygenilla "
                      "l‰hdekoodista projektille "+s"; // "Generated automatically by Doxygen" ... "for" ... "from the sourcecode"
      //if (s) result+=(QCString)" voor "+s;
      // t‰ss‰ on ongelma, kuinka taivuttaa parametria, esim. "Jcad"+"in"; "IFC2VRML konversio"+"n"
      // mutta ratkaistaan ongelma k‰tev‰sti kaksoispisteell‰ -> "Jcad:n" / "IFC2VRML konversio:n"
      // lopputulos on v‰hemm‰n kˆkkˆ ja t‰ysin luettava, mutta ei kuitenkaan t‰ydellinen.
      //
      // kierret‰‰n ongelma taivuttamalla sanaa projekti :)
      return result;
    }

    /*! put after an enum name in the list of all members */
    QCString trEnumName()
    { return "enumeraation nimi"; } // "enum name"

    /*! put after an enum value in the list of all members */
    QCString trEnumValue()
    { return "enumeraation arvo"; } // "enum value"

    /*! put after an undocumented member in the list of all members */
    QCString trDefinedIn()
    { return "m‰‰ritelty"; } // "defined in"

    // quick reference sections

    /*! This is put above each page as a link to the list of all groups of 
     *  compounds or files (see the \\group command).
     */
    QCString trModules()
    { return "Moduulit"; } // "Modules"
    
    /*! This is put above each page as a link to the class hierarchy */
    QCString trClassHierarchy()
    { return "Luokkahierarkia"; } // "Class Hierarchy"
   
    /*! This is put above each page as a link to the list of annotated classes */ 
    QCString trCompoundList()
    virtual QCString trCompoundList()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueet"; // "Data Structures"
      }
      else
      {
        return "Luokkalista"; // "Class List"
      }
    }

    /*! This is put above each page as a link to the list of documented files */
    QCString trFileList()
    { return "Tiedostolista"; } // "File List"
   
    /*! This is put above each page as a link to all members of compounds. */ 
    virtual QCString trCompoundMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueen kent‰t"; // "Data Fields" 
      }
      else
      {
        return "Luokan j‰senet"; // "Class Members"
      }
    }
    
    /*! This is put above each page as a link to all members of files. */
    virtual QCString trFileMembers()
    { 
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Globaalit"; // "Globals" 
      }
      else
      {
        return "Tiedoston j‰senet"; // "File Members"
      }
    }

    /*! This is put above each page as a link to all related pages. */
    QCString trRelatedPages()
    { return "Liittyv‰t sivut"; } // "Related Pages"
   
    /*! This is put above each page as a link to all examples. */ 
    QCString trExamples()
    { return "Esimerkit"; } // "Examples"
   
    /*! This is put above each page as a link to the search engine. */ 
    QCString trSearch()
    { return "Etsi"; } // "Search"
   
    /*! This is an introduction to the class hierarchy. */ 
    QCString trClassHierarchyDescription()
    { return "T‰m‰ periytymislista on p‰‰tasoltaan aakkostettu " // "This inheritance list is sorted roughly, "
             "mutta alij‰senet on aakkostettu itsen‰isesti:"; // "but not completely, alphabetically:";
    }

    /*! This is an introduction to the list with all files. */
    QCString trFileListDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista ";
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="tiedostoista lyhyen selitteen kera:"; // "files with brief descriptions:"
      return result;
    }
    
    /*! This is an introduction to the annotated compound list. */
    QCString trCompoundListDescription()
    {
    
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "T‰ll‰ ovat tietueet lyhyen selitteen kera:"; // "Here are the data structures with brief descriptions:"
      }
      else
      {
        return "T‰‰ll‰ ovat luokat, tietueet ja " // "Here are the classes, structs and "
             "yhdisteet lyhyen selitteen kera:"; // "unions with brief descriptions:"
      }
    }
    
    /*! This is an introduction to the page with all class members. */
    QCString trCompoundMembersDescription(bool extractAll)
    {
      {
      QCString result="T‰‰ll‰ on lista kaikista " // "Here is a list of all "
      if (!extractAll)
      {
        result+="dokumentoiduista "; // "documented "
      }
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="tietuiden ja yhdisteiden kentist‰"; // "struct and union fields"
      }
      else
      {
        result+="luokkien j‰senist‰"; // "class members"
      }
      result+=" linkitettyin‰ "; // " with links to "
      if (!extractAll) 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+="jokaisen kent‰n tietueen/yhdisteen dokumentaatioon:"; // "the struct/union documentation for each field:"
        }
        else
        {
          result+="jokaisen j‰senen luokkadokumentaatioon:"; // "the class documentation for each member:"
        }
      }
      else 
      {
        if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
        {
          result+= "tietueisiin/yhdisteisiin, joihin ne kuuluvat:"; // "the structures/unions they belong to:"
        }
        else
        {
          result+="luokkiin, joihin ne kuuluvat"; //"the classes they belong to:"
        }
      }
      return result;
    }

    /*! This is an introduction to the page with all file members. */
    QCString trFileMembersDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        result+="funktioista, muuttujista, m‰‰rittelyist‰, luetteloista ja tyyppim‰‰rittelyist‰"; // "functions, variables, defines, enums, and typedefs"
      }
      else
      {
        result+="tiedoston j‰senist‰"; // "file members"
      }
      result+=" linkitettyin‰ "; // " with links to "
      if (extractAll) 
        result+="tiedostoon, johon ne kuuluvat:"; // "the files they belong to:"
      else 
        result+="dokumentaatioon:"; // "the documentation:"
      return result;
    }
    
    /*! This is an introduction to the page with the list of all examples */
    QCString trExamplesDescription()
    { return "T‰‰ll‰ on lista kaikista esimerkeist‰:"; } //  "Here is a list of all examples:"
   
    /*! This is an introduction to the page with the list of related pages */ 
    QCString trRelatedPagesDescription()
    { return "T‰‰ll‰ on lista kaikista liittyvist‰ dokumentaatiosivuista:"; } // "Here is a list of all related documentation pages:"
   
    /*! This is an introduction to the page with the list of class/file groups */ 
    QCString trModulesDescription()
    { return "T‰‰ll‰ on lista kaikista moduleista:"; } // "Here is a list of all modules:"
    
    // index titles (the project name is prepended for these) 
    
    /*! This is used in HTML as the title of index.html. */
    QCString trDocumentation()
    { return "Dokumentaatio"; } // "Documentation"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * index of all groups.
     */
    QCString trModuleIndex()
    { return "Moduuliluettelo"; } // "Module Index"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * class hierarchy.
     */
    QCString trHierarchicalIndex()
    { return "Hierarkinen luettelo"; } // "Hierarchical Index"
    
    /*! This is used in LaTeX as the title of the chapter with the 
     * annotated compound index.
     */
    QCString trCompoundIndex()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      { 
        return "Tietueluettelo"; // "Data Structure Index"
      }
      else
      {
        return "Luokkaluettelo"; // "Class Index"
      }
    }
    
    /*! This is used in LaTeX as the title of the chapter with the
     * list of all files.
     */
    QCString trFileIndex() 
    { return "Tiedostoluettelo"; } // "File Index"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all groups.
     */
    QCString trModuleDocumentation()
    { return "Moduulin dokumentaatio"; } // "Module Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all classes, structs and unions.
     */
    QCString trClassDocumentation()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueen dokumentaatio"; // "Data Structure Documentation"
      }
      else
      {
        return "Luokan dokumentaatio"; // "Class Documentation"
      }
    }

    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all files.
     */
    QCString trFileDocumentation()
    { return "Tiedoston dokumentaatio"; } // "File Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all examples.
     */
    QCString trExampleDocumentation()
    { return "Esimerkkien dokumentaatio"; } // "Example Documentation"
    
    /*! This is used in LaTeX as the title of the chapter containing
     *  the documentation of all related pages.
     */
    QCString trPageDocumentation()
    { return "Sivujen dokumentaatio"; } // "Page Documentation"
    
    /*! This is used in LaTeX as the title of the document */
    QCString trReferenceManual()
    { return "K‰sikirja"; } // "Reference Manual"

    /*! This is used in the documentation of a file as a header before the 
     *  list of defines
     */
    QCString trDefines()
    { return "M‰‰rittelyt"; } // "Defines"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of function prototypes
     */
    QCString trFuncProtos()
    { return "Funktioiden prototyypit"; } // "Function Prototypes"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of typedefs
     */
    QCString trTypedefs()
    { return "Tyyppim‰‰rittelyt"; } // "Typedefs"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of enumerations
     */
    QCString trEnumerations()
    { return "Luettelotyypit"; } // "Enumerations"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) functions
     */
    QCString trFunctions()
    { return "Funktiot"; } // "Functions"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    QCString trVariables()
    { return "Muuttujat"; } // "Variables"
    
    /*! This is used in the documentation of a file as a header before the 
     *  list of (global) variables
     */
    QCString trEnumerationValues()
    { return "Luettelotyyppien arvot"; } // "Enumerator"

    /*! This is used in the documentation of a file before the list of
     *  documentation blocks for defines
     */
    QCString trDefineDocumentation()
    { return "M‰‰ritysten dokumentointi"; } // "Define Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for function prototypes
     */
    QCString trFunctionPrototypeDocumentation()
    { return "Funktioprototyyppien dokumentaatio"; } // "Function Prototype Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for typedefs
     */
    QCString trTypedefDocumentation()
    { return "Tyyppim‰‰ritysten dokumentaatio"; } // "Typedef Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for enumeration types
     */
    QCString trEnumerationTypeDocumentation()
    { return "Luettelotyyppien dokumentaatio"; } // "Enumeration Type Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for functions
     */
    QCString trFunctionDocumentation()
    { return "Funktioiden dokumentaatio"; } // "Function Documentation"
    
    /*! This is used in the documentation of a file/namespace before the list 
     *  of documentation blocks for variables
     */
    QCString trVariableDocumentation()
    { return "Muuttujien dokumentaatio"; } // "Variable Documentation"
    
    /*! This is used in the documentation of a file/namespace/group before 
     *  the list of links to documented compounds
     */
    QCString trCompounds()
    {
      if (Config_getBool("OPTIMIZE_OUTPUT_FOR_C"))
      {
        return "Tietueet"; // "Data Structures"
      }
      else
      {
        return "Luokat"; // "Classes"
      }
    }
    
    /*! This is used in the standard footer of each page and indicates when 
     *  the page was generated 
     */
    QCString trGeneratedAt(const char *date,const char *projName)
    { 
        // funktio on hiukan vaikea k‰‰nt‰‰ prepositioihin sidotun rakenteen vuoksi.
      QCString result=(QCString)"Generoitu "+date; // "Generated on "
      if (projName) result+=(QCString)" projektille "+projName; // " for "
      result+=(QCString)" tekij‰: "; // " by"
      return result;
    }
    /*! This is part of the sentence used in the standard footer of each page.
     */
    QCString trWrittenBy()
    {
      return "kirjoittanut"; // "written by"
    }

    /*! this text is put before a class diagram */
    QCString trClassDiagram(const char *clName)
    {
      return "Luokan "+(QCString)clName+" luokkakaavio"; // "Inheritance diagram for "
    }

    /*! this text is generated when the \\internal command is used. */
    QCString trForInternalUseOnly()
    { return "Vain sis‰iseen k‰yttˆˆn."; } // "For internal use only."
    
    /*! this text is generated when the \\warning command is used. */
    QCString trWarning()
    { return "Varoitus"; } // "Warning"
    
    /*! this text is generated when the \\version command is used. */
    QCString trVersion()
    { return "Versio"; } // "Version"
    
    /*! this text is generated when the \\date command is used. */
    QCString trDate()
    { return "P‰iv‰ys"; } // "Date"
    
    /*! this text is generated when the \\return command is used. */
    QCString trReturns()
    { return "Palauttaa"; } // "Returns"
    
    /*! this text is generated when the \\sa command is used. */
    QCString trSeeAlso()
    { return "Katso myˆs"; } // "See also"
    
    /*! this text is generated when the \\param command is used. */
    QCString trParameters()
    { return "Parametrit"; } // "Parameters"
    
    /*! this text is generated when the \\exception command is used. */
    QCString trExceptions()
    { return "Poikkeukset"; } // "Exceptions"
    
    /*! this text is used in the title page of a LaTeX document. */
    QCString trGeneratedBy()
    { return "Generoinut"; } // "Generated by"
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990307 
//////////////////////////////////////////////////////////////////////////
    
    /*! used as the title of page containing all the index of all namespaces. */
    QCString trNamespaceList()
    { return "Nimiavaruus Lista"; } // "Namespace List"
    
    /*! used as an introduction to the namespace list */
    QCString trNamespaceListDescription(bool extractAll)
    {
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="nimiavaruuksista lyhyen selitteen kera:"; // "namespaces with brief descriptions:"
      return result;
    }
    
    /*! used in the class documentation as a header before the list of all
     *  friends of a class
     */
    QCString trFriends()
    { return "Yst‰v‰t"; } // "Friends"

//////////////////////////////////////////////////////////////////////////
// new since 0.49-990405
//////////////////////////////////////////////////////////////////////////
    
    /*! used in the class documentation as a header before the list of all
     * related classes 
     */
    QCString trRelatedFunctionDocumentation()
    { return "Yst‰v‰t ja niihin liittyvien funktioiden dokumentaatio"; } // "Friends And Related Function Documentation"
    
//////////////////////////////////////////////////////////////////////////
// new since 0.49-990425
//////////////////////////////////////////////////////////////////////////

    /*! used as the title of the HTML page of a class/struct/union */
    virtual QCString trCompoundReference(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool isTemplate)
    {
      QCString result=(QCString)clName;
      switch(compType)
      {
        case ClassDef::Class:      result+=" Luokka"; break; // " Class"
        case ClassDef::Struct:     result+=" Tietue"; break; // " Struct"
        case ClassDef::Union:      result+=" Yhdiste"; break; // " Union"
        case ClassDef::Interface:  result+=" Rajapinta"; break; // " Interface"
        case ClassDef::Protocol:   result+=" Protokolla"; break; // " Protocol"
        case ClassDef::Category:   result+=" Category"; break;
        case ClassDef::Exception:  result+=" Exception"; break;
      }
      if (isTemplate) result+=" Template";
      result+=" Reference";
      return result;
    }
    virtual QCString trCompoundReference(const char *clName,
                                    ClassDef::CompoundType compType,
                                    bool /*isTemplate*/)
      // used as the title of the HTML page of a class/struct/union
    {
      QCString result=(QCString)clName+" ";
      switch(compType)
      {
        case ClassDef::Class:  result+=" Luokka"; break; // "Class"
        case ClassDef::Struct: result+=" Struct"; break; // "Struct"
        case ClassDef::Union:  result+=" Union"; break; // "Union"
        case ClassDef::Interface: result+=" Interface"; break; // "Interface"
        case ClassDef::Protocol: result+=" Protocol"; break; // translate me!
        case ClassDef::Category: result+=" Category"; break; // translate me!
        case ClassDef::Exception: result+=" Exception"; break; // "Interface"
      }
      result+=" Referenssi"; // " Reference"
      return result;
    }
    
    virtual QCString trFileReference(const char *fileName)
      // used as the title of the HTML page of a file
    {
      QCString result=fileName;
      result+=" Tiedosto Referenssi"; // " File Reference"
      return result;
    }
    
    virtual QCString trNamespaceReference(const char *namespaceName)
      // used as the title of the HTML page of a namespace
    {
      QCString result=namespaceName;
      result+=" Nimiavaruus Referenssi"; // " Namespace Reference"
      return result;
    }
    
    // these are for the member sections of a class, struct or union 
    virtual QCString trPublicMembers()
    { return "Julkiset J‰senet"; } // "Public Members"
    
    virtual QCString trPublicSlots()
    { return "Julkiset Slotit"; } // "Public Slots"
    
    virtual QCString trSignals()
    { return "Signaalit"; } // "Signals"
    
    virtual QCString trStaticPublicMembers()
    { return "Staattiset Julkiset J‰senet"; } // "Static Public Members"
    
    virtual QCString trProtectedMembers()
    { return "Suojatut J‰senet"; } // "Protected Members"
    
    virtual QCString trProtectedSlots()
    { return "Suojatut Slotit"; } // "Protected Slots"
    
    virtual QCString trStaticProtectedMembers()
    { return "Staattiset Suojatut J‰senet"; } // "Static Protected Members"
    
    virtual QCString trPrivateMembers()
    { return "Yksityiset J‰senet"; } // "Private Members"
    
    virtual QCString trPrivateSlots()
    { return "Yksityiset Slotit"; } // "Private Slots"
    
    virtual QCString trStaticPrivateMembers()
    { return "Staattiset Yksityiset J‰senet"; } // "Static Private Members"
    // end of member sections 
    
    virtual QCString trWriteList(int numEntries)
    {
      // this function is used to produce a comma-separated list of items.
      // use generateMarker(i) to indicate where item i should be put.
      QCString result;
      int i;
      // the inherits list contain `numEntries' classes
      for (i=0;i<numEntries;i++) 
      {
        // use generateMarker to generate placeholders for the class links!
        result+=generateMarker(i); // generate marker for entry i in the list 
                                   // (order is left to right)
        
        if (i!=numEntries-1)  // not the last entry, so we need a separator
        {
          if (i<numEntries-2) // not the fore last entry 
            result+=", ";
          else                // the fore last entry
            result+=" ja "; // ", and "
        }
      }
      return result; 
    }
    
    virtual QCString trInheritsList(int numEntries)
      // used in class documentation to produce a list of base classes,
      // if class diagrams are disabled.
    {
      return "Perij‰t "+trWriteList(numEntries)+"."; // "Inherits "
    }
    
    virtual QCString trInheritedByList(int numEntries)
      // used in class documentation to produce a list of super classes,
      // if class diagrams are disabled.
    {
      return "Periytyy "+trWriteList(numEntries)+"."; // "Inherited by "
    }
    
    virtual QCString trReimplementedFromList(int numEntries)
      // used in member documentation blocks to produce a list of 
      // members that are hidden by this one.
    {
      return "Uudelleen toteutettu "+trWriteList(numEntries)+"."; // "Reimplemented from "
    }
    
    virtual QCString trReimplementedInList(int numEntries)
    {
      // used in member documentation blocks to produce a list of
      // all member that overwrite the implementation of this member.
      return "Uudelleen toteutettu "+trWriteList(numEntries)+"."; // "Reimplemented in "
    }

    virtual QCString trNamespaceMembers()
      // This is put above each page as a link to all members of namespaces.
    { return "Nimiavaruuden j‰senet"; } // "Namespace Members"
    
    virtual QCString trNamespaceMemberDescription(bool extractAll)
      // This is an introduction to the page with all namespace members
    { 
      QCString result="T‰‰ll‰ on lista kaikista "; // "Here is a list of all "
      if (!extractAll) result+="dokumentoiduista "; // "documented "
      result+="nimiavaruuden j‰senist‰ linkitettyn‰ "; // "namespace members with links to "
      if (extractAll) 
        result+="nimiavaruuden dokumentaatioon johon ne kuuluvat:"; // "the namespace documentation for each member:";
      else 
        result+="nimiavaruuteen johon ne kuuluvat:"; // "the namespaces they belong to:"
      return result;
    }
    
    virtual QCString trNamespaceIndex()
      // This is used in LaTeX as the title of the chapter with the 
      // index of all namespaces.
    { return "Nimiavaruuden Indeksi"; } // "Namespace Index"
    
    virtual QCString trNamespaceDocumentation()
      // This is used in LaTeX as the title of the chapter containing
      // the documentation of all namespaces.
    { return "Nimiavaruuden Dokumentaatio"; } // "Namespace Documentation"
};

#endif
