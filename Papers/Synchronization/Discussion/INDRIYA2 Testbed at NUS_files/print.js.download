function printDiv(id) {
    var element = document.getElementById(id);
    
    var htmlToPrint = '' +
        '<style type="text/css">' +
        'table th, table td {' +
        'border:1px solid #000;' +
        'padding;0.5em;' +
        '}' +
        '</style>';

    if(id == "userInfoTable") {
        var temp = element.cloneNode(true);

        var quota = document.getElementById("quotatxt");
        temp.rows[0].cells[1].innerHTML = quota.value;
        
        //quota.replaceWith(document.createTextNode(quota.value));

        var admin = document.getElementById("adminList");
        temp.rows[1].cells[1].innerHTML = admin.options[admin.selectedIndex].innerHTML;
        //admin.replaceWith(document.createTextNode(admin.options[admin.selectedIndex].innerHTML));

        var motes = document.getElementById("allMotesList");
        temp.rows[2].cells[1].innerHTML = motes.options[motes.selectedIndex].innerHTML;
        //motes.replaceWith(document.createTextNode(motes.options[admin.selectedIndex].innerHTML));

        var userDetails = document.getElementById("userDetails");
        temp.rows[6].cells[1].innerHTML = userDetails.value;

        htmlToPrint += temp.outerHTML;
    } else {
        htmlToPrint += element.outerHTML;
    }
    
    newWin = window.open("");
    newWin.document.write(htmlToPrint);
    newWin.print();
    newWin.close();
}
