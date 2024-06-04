var addon = require('bindings')('Release/myAddon.node');

console.log(addon.get_date("123", "123"));

function addDate() {
    let date = prompt("Дата события дд.мм.гггг");
    let event = prompt("Какое событие?");

    console.log(addon.get_date(date, event));

    const el = document.getElementById("dateTable").innerHTML; 
    el += addon.get_date(date, event);
}

function delDate() {
    let Index = prompt("Какое событие удалить (Введите №)");
}