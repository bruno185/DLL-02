// DLLCall.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include <windows.h>
#include <stdio.h>

__declspec(dllimport) int multip();


int main(void)
{
#ifdef _WIN64
    HINSTANCE hinst = LoadLibraryA("DLL-02.dll");
#else
    HINSTANCE hinst = LoadLibraryA("DLL-02.dll");
#endif

    std::cout << "Hello World!\n";
    if (hinst)
    {
        puts("DLL loaded");
        typedef int (*FNPTR)();
        FNPTR myfunc = (FNPTR)GetProcAddress(hinst, "multip");

        //EDIT: For additional safety, check to see if it loaded
        if (!myfunc) {
            //ERROR.  Handle it.
            std::cout << "Erreur !\n";
        }
        else {
            //Call it!
            int i = myfunc();
            std::cout << "Resultat : "  << std::hex << i <<"h";
        }
    }
    else
        puts("NG");


    FreeLibrary(hinst);




    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
