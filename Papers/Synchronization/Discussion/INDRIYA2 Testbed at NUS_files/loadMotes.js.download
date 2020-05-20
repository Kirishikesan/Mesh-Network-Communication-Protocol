function loadMotes() {
    var userInfo = new FormData();
    userInfo.append('userID', userID);

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'php/getMotes.php', true);
    xhr.send(userInfo);
    xhr.onload = function () {
        if (xhr.status === 200) {
            var xmlDoc = xhr.responseXML;
            if(xmlDoc != null){
                //add mote types to mote types table
                var table=document.getElementById("moteTypes_data_table");
                var table_len=(table.rows.length)-1;
                
                for(var i = 1; i < table_len; i++) {
                    table.rows[1].outerHTML = "";
                }
                
                var table_len=(table.rows.length)-1;
                
                var moteTypesList = document.getElementById("moteTypesList_load");
                moteTypesList.innerHTML = "";
                
                for(var i = 0; i < xmlDoc.getElementsByTagName("moteTypes")[0].childNodes.length; i++) {
                    var moteTypeID = xmlDoc.getElementsByTagName("moteTypeID")[i].childNodes[0].nodeValue;
                    
                    var moteTypeName = xmlDoc.getElementsByTagName("moteTypeName")[i].childNodes[0].nodeValue;
                    
                    var row = table.insertRow(table_len).outerHTML="<tr id='moteType_row"+moteTypeID+"'><td id='name_moteType_row"+moteTypeID+"'>"+moteTypeName+"</td><td><input class='button' type='button' id='edit_moteType_button"+moteTypeID+"' value='Edit' class='edit' onclick='edit_moteType_row("+moteTypeID+")' style='float: left'> <input class='button' type='button' id='save_moteType_button"+moteTypeID+"' value='Save' class='save' onclick='save_moteType_row("+moteTypeID+")' style='display: none''> <input class='button' type='button' value='Delete' class='delete' onclick='delete_moteType_row("+moteTypeID+")' style='float: left'></td></tr>";
                    
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode(xmlDoc.getElementsByTagName("moteTypeName")[i].childNodes[0].nodeValue));

                    option.value = xmlDoc.getElementsByTagName("moteTypeID")[i].childNodes[0].nodeValue;
                    moteTypesList.appendChild(option);
                }
                
                //add clusters to clusters table
                var table=document.getElementById("clusters_data_table");
                var table_len=(table.rows.length)-1;

                for(var i = 1; i < table_len; i++) {
                    table.rows[1].outerHTML = "";
                }

                var table_len=(table.rows.length)-1;
                
                var clustersList = document.getElementById("clustersList_load");
                clustersList.innerHTML = "";

                for(var i = 0; i < xmlDoc.getElementsByTagName("clusters")[0].childNodes.length; i++) {
                    var clusterID = xmlDoc.getElementsByTagName("clusterID")[i].childNodes[0].nodeValue;

                    var clusterName = xmlDoc.getElementsByTagName("clusterName")[i].childNodes[0].nodeValue;
                    
                    var floorLevel = xmlDoc.getElementsByTagName("floorLevel")[i].childNodes[0].nodeValue;

                    var row = table.insertRow(table_len).outerHTML="<tr id='cluster_row"+clusterID+"'><td id='name_cluster_row"+clusterID+"'>"+clusterName+"</td><td id='name_floorLevel_row"+clusterID+"'>"+floorLevel+"</td><td><input class='button' type='button' id='edit_cluster_button"+clusterID+"' value='Edit' class='edit' onclick='edit_cluster_row("+clusterID+")' style='float: left'> <input class='button' type='button' id='save_cluster_button"+clusterID+"' value='Save' class='save' onclick='save_cluster_row("+clusterID+")' style='display: none''> <input class='button' type='button' value='Delete' class='delete' onclick='delete_cluster_row("+clusterID+")' style='float: left'></td></tr>";
                    
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode(xmlDoc.getElementsByTagName("clusterName")[i].childNodes[0].nodeValue));

                    option.value = xmlDoc.getElementsByTagName("clusterID")[i].childNodes[0].nodeValue;
                    clustersList.appendChild(option);
                }
                
                //add motes to motes table
                var table=document.getElementById("motes_data_table");
                var table_len=(table.rows.length)-1;

                for(var i = 1; i < table_len; i++) {
                    table.rows[1].outerHTML = "";
                }

                var table_len=(table.rows.length)-1;

                for(var i = 0; i < xmlDoc.getElementsByTagName("motes")[0].childNodes.length; i++) {
                    var moteID = xmlDoc.getElementsByTagName("moteID")[i].childNodes[0].nodeValue;
                    
                    var physical_id = xmlDoc.getElementsByTagName("physical_id")[i].childNodes[0].nodeValue;
                    
                    var virtual_id = xmlDoc.getElementsByTagName("virtual_id")[i].childNodes[0].nodeValue;
                    
                    var gateway_ip = xmlDoc.getElementsByTagName("gateway_ip")[i].childNodes[0].nodeValue;
                    
                    var gateway_ttyid = xmlDoc.getElementsByTagName("gateway_ttyid")[i].childNodes[0].nodeValue;
                    
                    var gateway_port = xmlDoc.getElementsByTagName("gateway_port")[i].childNodes[0].nodeValue;
                    
                    var coordinates = xmlDoc.getElementsByTagName("coordinates")[i].childNodes[0].nodeValue;

                    var moteTypes_moteTypeID = xmlDoc.getElementsByTagName("moteTypes_moteTypeID")[i].childNodes[0].nodeValue;
                    var moteTypeName = getMoteTypeName(moteTypes_moteTypeID);
                    
                    var clusters_clusterID = xmlDoc.getElementsByTagName("clusters_clusterID")[i].childNodes[0].nodeValue;
                    var clusterName = getClusterName(clusters_clusterID);
                    
                    var status = xmlDoc.getElementsByTagName("status")[i].childNodes[0].nodeValue;
                    var status_val = "undefined";
                    if(status == 0)
                        status_val = "down";
                    if(status == 1)
                        status_val = "up";

                    var row = table.insertRow(table_len).outerHTML="<tr id='mote_row"+moteID+"'><td id='physical_id_row"+moteID+"'>"+physical_id+"</td><td id='virtual_id_row"+moteID+"'>"+virtual_id+"</td><td id='gateway_ip_row"+moteID+"'>"+gateway_ip+"</td><td id='gateway_ttyid_row"+moteID+"'>"+gateway_ttyid+"</td><td id='gateway_port_row"+moteID+"'>"+gateway_port+"</td><td id='coordinates_row"+moteID+"'>"+coordinates+"</td><td id='moteTypeName_row"+moteID+"'>"+moteTypeName+"</td><td id='clusterName_row"+moteID+"'>"+clusterName+"</td><td>"+status_val+"</td><td><input class='button' type='button' id='edit_mote_button"+moteID+"' value='Edit' class='edit' onclick='edit_mote_row("+moteID+")' style='float: left'> <input class='button' type='button' id='save_mote_button"+moteID+"' value='Save' class='save' onclick='save_mote_row("+moteID+")' style='display: none''> <input class='button' type='button' value='Delete' class='delete' onclick='delete_mote_row("+moteID+")' style='float: left'></td></tr>";
                }
            }
        }
    };
}

function addMoteTypes_load() {
    var userInfo = new FormData();
    userInfo.append('userID', userID);

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'php/getMoteTypes.php', true);
    xhr.send(userInfo);
    xhr.onload = function () {
        if (xhr.status === 200) {
            var xmlDoc = xhr.responseXML;
            if(xmlDoc != null){
                //add all motes to select options
                var moteTypesList = document.getElementById("moteTypesList_load");
                moteTypesList.innerHTML = "";
                
                for (i = 0; i < xmlDoc.getElementsByTagName("moteTypes")[0].childNodes.length; i++) {
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode(xmlDoc.getElementsByTagName("moteTypeName")[i].childNodes[0].nodeValue));
                    
                    option.value = xmlDoc.getElementsByTagName("moteTypeID")[i].childNodes[0].nodeValue;
                    moteTypesList.appendChild(option);
                }
            }
        }
    };
}

function addclusters_load() {
    var userInfo = new FormData();
    userInfo.append('userID', userID);

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'php/getclusters.php', true);
    xhr.send(userInfo);
    xhr.onload = function () {
        if (xhr.status === 200) {
            var xmlDoc = xmlhttp.responseXML;
            if(xmlDoc != null){
                //add all motes to select options
                var clustersList = document.getElementById("clustersList_load");
                clustersList.innerHTML = "";
                
                for (i = 0; i < xmlDoc.getElementsByTagName("clusters")[0].childNodes.length; i++) {
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode(xmlDoc.getElementsByTagName("clusterName")[i].childNodes[0].nodeValue));
                    
                    option.value = xmlDoc.getElementsByTagName("clusterID")[i].childNodes[0].nodeValue;
                    clustersList.appendChild(option);
                }
            }
        }
    };
}

function getMoteTypeName(moteTypeID) {
    var moteTypesList = document.getElementById("moteTypesList_load");
    for(var i = 0; i < moteTypesList.length; i++) {
        if(moteTypesList.options[i].value == moteTypeID)
            return moteTypesList.options[i].innerHTML;
    }
}

function getClusterName(clusterID) {
    var clustersList = document.getElementById("clustersList_load");
    for(var i = 0; i < clustersList.length; i++) {
        if(clustersList.options[i].value == clusterID)
            return clustersList.options[i].innerHTML;
    }
}