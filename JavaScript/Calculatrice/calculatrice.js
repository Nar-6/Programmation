window.onload = () => {

    const ecran = document.querySelector(".ecran");

    const un = document.querySelector("#un");
    const deux = document.querySelector("#deux");
    const trois = document.querySelector("#trois");
    const quatre = document.querySelector("#quatre");
    const cinq = document.querySelector("#cinq");
    const six = document.querySelector("#six");
    const sept = document.querySelector("#sept");
    const huit = document.querySelector("#huit");
    const neuf = document.querySelector("#neuf");
    const zero = document.querySelector("#zero");
    const plus = document.querySelector("#plus");
    const moins = document.querySelector("#moins");
    const fois = document.querySelector("#fois");
    const division = document.querySelector("#division");
    const virgule = document.querySelector("#virgule");
    const reset = document.querySelector("#reset");
    const egal = document.querySelector("#egal");

    const boutons = document.querySelectorAll(".boutons");

    let resultat = 0;
    let operateur = "";

    function calcul(){

        if (this == un) {
            ecran.innerHTML = ecran.innerHTML + "1";
        }
        else if (this == deux) {
            ecran.innerHTML = ecran.innerHTML + "2";
        }
        else if (this == trois) {
            ecran.innerHTML = ecran.innerHTML + "3";
        }
        else if (this == quatre) {
            ecran.innerHTML = ecran.innerHTML + "4";
        }
        else if (this == cinq) {
            ecran.innerHTML = ecran.innerHTML + "5";
        }
        else if (this == six) {
            ecran.innerHTML = ecran.innerHTML + "6";
        }
        else if (this == sept) {
            ecran.innerHTML = ecran.innerHTML + "7";
        }
        else if (this == huit) {
            ecran.innerHTML = ecran.innerHTML + "8";
        }
        else if (this == neuf) {
            ecran.innerHTML = ecran.innerHTML + "9";
        }
        else if (this == zero) {
            ecran.innerHTML = ecran.innerHTML + "0";
        }
        else if (this == plus) {
            resultat = resultat + parseInt(ecran.innerHTML);
            operateur = "+";
            ecran.innerHTML = "";
        }
        else if (this == moins) {
            resultat = parseInt(ecran.innerHTML);
            operateur = "-";
        }
        else if (this == fois) {
            resultat = parseInt(ecran.innerHTML);
            operateur = "*";
            ecran.innerHTML = "";
        }
        else if (this == division) {
            resultat = parseInt(ecran.innerHTML);
            operateur = "/";
            ecran.innerHTML = "";
        }
        else if (this == egal) {
            if (operateur == "+") {
                resultat = resultat + parseInt(ecran.innerHTML);
            }
            else if (operateur == "-") {
                resultat = resultat - parseInt(ecran.innerHTML);
            }
            else if (operateur == "*") {
                resultat = resultat * parseInt(ecran.innerHTML);
            }
            else if (operateur == "/") {
                resultat = resultat / parseInt(ecran.innerHTML);
            }
            ecran.innerHTML = resultat;
        }
        else if (this == reset) {
            resultat = 0;
            operateur = "";
            ecran.innerHTML = "";
        }
        else if (this == virgule) {
            ecran.innerHTML = ecran.innerHTML + ".";
        }
    }

    for (let i = 0; i < boutons.length; i++) {
        boutons[i].addEventListener("click", calcul);
    }

}    
