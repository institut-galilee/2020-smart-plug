$(document).ready(function(){
    $("#appliquer").click(function(){
        var valeuron = $("#choixDelayON").val();
        var valeurof = $("#choixDelayOF").val();
        var valeurdemH = $("#demH").val();
        var valeurdemM = $("#demM").val();
        var valeurcoupH = $("#coupH").val();
        var valeurcoupM = $("#coupM").val();
        $.post("delayOnOf",{
            valeurDelayON: valeuron,
            valeurDelayOF: valeurof,
            valeurcoupH: valeurcoupH,
            valeurcoupM: valeurcoupM,
            valeurdemH: valeurdemH,
            valeurdemM: valeurdemM

        });
    });
});

setInterval(function getData() {
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("valeurConsumation").innerHTML = this.responseText;
        }
    };

    xhttp.open("POST", "lireElectricite", true);
    xhttp.send();
}, 2000);

function onButton() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "on", true);
    xhttp.send();
}

function offButton() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("POST", "off", true);
    xhttp.send();
}
