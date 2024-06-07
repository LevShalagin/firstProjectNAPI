var addon = require('bindings')('myAddon');

console.log("---------------------------");
console.log(addon.get_date("123"));
console.log("---------------------------")



function addDate() {
    let date = prompt("Дата события дд.мм.гггг");
    let event = prompt("Какое событие?");
}

function delDate() {
    let Index = prompt("Какое событие удалить (Введите №)");
}