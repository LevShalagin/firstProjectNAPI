// var addon = require('bindings')('myAddon');

index = 1;

function addDate() {
    let Date = prompt("Дата события дд.мм.гггг");
    let Event = prompt("Какое событие?");

    let table = document.getElementById("dateTable");

    // формирование строки сделать через аддон
    document.getElementById("dateTable").innerHTML += "<tr><td>" + index + "</td><td>" + Date + "</td><td>" + Event + "</td>";
    index += 1;
}

function delDate() {
    let Index = prompt("Какое событие удалить (Введите №)");
}