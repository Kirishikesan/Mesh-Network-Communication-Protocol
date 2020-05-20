var add = 0;
var addedJobID = -1;

//add a new job
function addJob(){
    //get mote types and fill select options
    addMoteTypes(-5);
}

function addMoteTypes(def) {
    var addFilesTable = document.getElementById("addJobTable").getElementsByTagName('tbody')[0];
    addFilesTable.innerHTML = "";

    var telosb_addFilesTable = document.getElementById("add_job_telosb_table").getElementsByTagName('tbody')[0];
    telosb_addFilesTable.innerHTML = "";
    
    var userInfo = new FormData();
    userInfo.append('userID', userID);

    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'php/getMotes.php', true);
    xhr.send(userInfo);
    xhr.onload = function () {
        if (xhr.status === 200) {
            motesInfoXMLDoc = xhr.responseXML;
            if(motesInfoXMLDoc == null){
                alert("Sorry, but no motes in indriya right now.");
            } else if(motesInfoXMLDoc.getElementsByTagName("moteType").length == 0) {
                alert("Sorry, but no motes in indriya right now.");
            } else{
                var jobsTableDiv = document.getElementById("jobsTableDiv");
                jQuery(jobsTableDiv).toggle('slow');

                var jobNametxt = document.getElementById("jobNametxt");
                jobNametxt.value = "";

                document.getElementById("associationJobDiv").style.display = "none";
                
                var addJobDiv = document.getElementById("addJobDiv");
                
                //add all motes to select options
                var moteTypesList = document.getElementById("moteTypesList");
                moteTypesList.innerHTML = "";
                
                var option = document.createElement("option");
                option.appendChild(document.createTextNode("-- select an option --"));
                option.style.visibility = "hidden";
                moteTypesList.appendChild(option);
                
                useAllMotes = motesInfoXMLDoc.getElementsByTagName("allMotes")[0].childNodes[0].nodeValue;
                
                for (i = 0; i < motesInfoXMLDoc.getElementsByTagName("moteTypes")[0].childNodes.length; i++) {
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode(motesInfoXMLDoc.getElementsByTagName("moteTypeName")[i].childNodes[0].nodeValue));
                    
                    option.value = motesInfoXMLDoc.getElementsByTagName("moteTypeID")[i].childNodes[0].nodeValue;
                    moteTypesList.appendChild(option);
                }
                
                if(useAllMotes == 1){
                    var option = document.createElement("option");
                    option.appendChild(document.createTextNode("All"));
                    option.value = -1;
                    moteTypesList.appendChild(option);
                }
                
                if(def != -5) {
                    //edit job, show update buttons and hide add buttons
                    document.getElementById("addJobLegend").innerHTML = "Edit \"" + data.get('jobName') + "\" Job";
                    
                    document.getElementById("nextAddJobButtons").style.display = "none";
                    document.getElementById("nextUpdateJobButtons").style.display = "block";
                    
                    //set job name
                    document.getElementById("jobNametxt").value = data.get("jobName");
                    
                    //set old files
                    
                    //set selected mote type
                    if(def == -1 && useAllMotes == 1){
                        moteTypesList.value = -1;
                    }
                    else{
                        moteTypesList.value = def;
                    }
                    add = 0;
                    moteTypesList.onchange();
                } else {
                    add = 1;
                    
                    document.getElementById("addJobLegend").innerHTML = "Add a new job";
                    
                    document.getElementById("nextAddJobButtons").style.display = "block";
                    document.getElementById("nextUpdateJobButtons").style.display = "none";
                }
                
                jQuery(addJobDiv).toggle('slow');
            }
        }
    };
}

var telosb_index = 0;

function moteTypeSelected() {
    var addFilesTable = document.getElementById("addJobTable").getElementsByTagName('tbody')[0];
    addFilesTable.innerHTML = "";

    var telosb_addFilesTable = document.getElementById("add_job_telosb_table").getElementsByTagName('tbody')[0];
    telosb_addFilesTable.innerHTML = "";
    
    var moteTypesList = document.getElementById("moteTypesList");
    
    if(moteTypesList.options[moteTypesList.selectedIndex].value == -1){
        for(i = 1; i < moteTypesList.length - 1; i++) {
            if(dcube == 1 && moteTypesList.options[i].innerHTML == "telosb"){
                telosb_index = i;
                var trMoteType = document.createElement("tr");
                trMoteType.style.color = "black";
                //mote type label td
                var tdMote = document.createElement("td");
                tdMote.setAttribute("colspan", "3");
                var moteTypeLabel = document.createElement("label");
                moteTypeLabel.appendChild(document.createTextNode("For Mote Type " + moteTypesList.options[i].innerHTML + ":"));
                moteTypeLabel.classList.add("text1");
                tdMote.appendChild(moteTypeLabel);
                trMoteType.appendChild(tdMote);
                addFilesTable.appendChild(trMoteType);

                var tr = document.createElement("tr");              
                //label file td
                var tdLabel = document.createElement("td");
                var labelFile = document.createElement("label");
                labelFile.appendChild(document.createTextNode("Include DCube Nodes: "));
                labelFile.classList.add("text1");
                var required = document.createElement("abbr");
                required.appendChild(document.createTextNode("*"));
                required.title = "required";
                labelFile.appendChild(required);
                tdLabel.appendChild(labelFile);
                tr.appendChild(tdLabel);
                //select field td
                var tdFile = document.createElement("td");
                var dcube_select = document.createElement("select");
                dcube_select.classList.add("text1");
                dcube_select.options[dcube_select.options.length] = new Option('Yes', 'dcube_yes');
                dcube_select.options[dcube_select.options.length] = new Option('No', 'dcube_no');
                // dcube_select.options[dcube_select.options.length] = new Option('Only DCube', 'dcube_only');
                dcube_select.onchange = dcube_select_changed;
                dcube_select.id = "dcube_select";
                tdFile.appendChild(dcube_select);
                tr.appendChild(tdFile);
                addFilesTable.appendChild(tr);

                if(add == 0){
                    if(data.get("dcube") == 0)
                        dcube_select.value = "dcube_no";
                    else if(data.get("dcube") == 2)
                        dcube_select.value = "dcube_yes";
                }
                dcube_select.onchange();
            } else{
                var trMoteType = document.createElement("tr");
                trMoteType.style.color = "black";
                //mote type label td
                var tdMote = document.createElement("td");
                tdMote.setAttribute("colspan", "3");
                var moteTypeLabel = document.createElement("label");
                moteTypeLabel.appendChild(document.createTextNode("For Mote Type " + moteTypesList.options[i].innerHTML + ":"));
                moteTypeLabel.classList.add("text1");
                tdMote.appendChild(moteTypeLabel);
                trMoteType.appendChild(tdMote);
                addFilesTable.appendChild(trMoteType);
                
                var tr = document.createElement("tr");
                
                //label file td
                var tdLabel = document.createElement("td");
                
                var labelFile = document.createElement("label");
                labelFile.appendChild(document.createTextNode("Add File(s): "));
                labelFile.classList.add("text1");
                
                var required = document.createElement("abbr");
                required.appendChild(document.createTextNode("*"));
                required.title = "required";
                labelFile.appendChild(required);
                
                tdLabel.appendChild(labelFile);
                
                tr.appendChild(tdLabel);
                
                //old filed list
                if(add == 0) {
                    var trOldFiles = document.createElement("tr");
                    
                    //label file td
                    var tdLabel = document.createElement("td");
                    var labelFile = document.createElement("label");
                    labelFile.appendChild(document.createTextNode("Old File(s): "));
                    labelFile.classList.add("text1");
                    tdLabel.appendChild(labelFile);
                    
                    //old files td
                    var tdSelect = document.createElement("td");
                    var select = document.createElement("select");
                    select.classList.add("text1");
                    select.id = moteTypesList.options[i].value + "@OldFilesList";
                    select.size = "5";
                    jQuery(select).attr('multiple', 'multiple');
                    //file select
                    var moteTypeID = moteTypesList.options[i].value;
                    var oldFileID = data.getAll("oldFileID" + moteTypeID + "[]");
                    var oldFileName = data.getAll("oldFileName" + moteTypeID + "[]");
                    for(var k = 0; k < oldFileID.length; k++) {
                        var option = document.createElement("option"); option.appendChild(document.createTextNode(oldFileName[k]));
                        option.value = oldFileID[k];
                        select.appendChild(option);
                    }
                    tdSelect.appendChild(select);
                    
                    //delete button td
                    var tdDeleteButton = document.createElement("td");
                    tdDeleteButton.style.verticalAlign = "bottom";
                    var deleteBtn = document.createElement("input");
                    deleteBtn.classList.add("button");
                    deleteBtn.type = "button";
                    deleteBtn.title = "Delete selected file(s)";
                    deleteBtn.id = moteTypesList.options[i].value + "@deleteFile";
                    deleteBtn.onclick = deleteSelectedFile;
                    deleteBtn.value = "Delete Files";
                    tdDeleteButton.appendChild(deleteBtn);
                    
                    
                    trOldFiles.appendChild(tdLabel);
                    trOldFiles.appendChild(tdSelect);
                    trOldFiles.appendChild(tdDeleteButton);
                    
                    addFilesTable.appendChild(trOldFiles);
                }

                //input file td
                var tdFile = document.createElement("td");
                
                var inputFile = document.createElement("input");
                inputFile.type = "file";
                inputFile.classList.add("text1");
                jQuery(inputFile).attr('multiple', 'multiple');
                inputFile.id = moteTypesList.options[i].value + "@inputFile";
                tdFile.appendChild(inputFile);
                tr.appendChild(tdFile);
                
                addFilesTable.appendChild(tr);
            }
        }
        
    } else{
        if(dcube == 1 && moteTypesList.options[moteTypesList.selectedIndex].innerHTML == "telosb"){
            telosb_index = moteTypesList.selectedIndex;
            var tr = document.createElement("tr");                
            
            //label file td
            var tdLabel = document.createElement("td");
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Include DCube Nodes: "));
            labelFile.classList.add("text1");
            var required = document.createElement("abbr");
            required.appendChild(document.createTextNode("*"));
            required.title = "required";
            labelFile.appendChild(required);
            tdLabel.appendChild(labelFile);
            tr.appendChild(tdLabel);

            //select field td
            var tdFile = document.createElement("td");
            var dcube_select = document.createElement("select");
            dcube_select.classList.add("text1");
            dcube_select.options[dcube_select.options.length] = new Option('Yes', 'dcube_yes');
            dcube_select.options[dcube_select.options.length] = new Option('No', 'dcube_no');
            // dcube_select.options[dcube_select.options.length] = new Option('Only DCube', 'dcube_only');
            dcube_select.id = "dcube_select";
            dcube_select.onchange = dcube_select_changed;
            tdFile.appendChild(dcube_select);
            tr.appendChild(tdFile);
            
            addFilesTable.appendChild(tr);

            if(add == 0){
                if(data.get("dcube") == 0)
                    dcube_select.value = "dcube_no";
                else if(data.get("dcube") == 2)
                    dcube_select.value = "dcube_yes";
            }
            dcube_select.onchange();
        } else{
            var trMoteType = document.createElement("tr");
            trMoteType.style.color = "black";
            //mote type label td
            var tdMote = document.createElement("td");
            tdMote.setAttribute("colspan", "3");
            var moteTypeLabel = document.createElement("label");
            moteTypeLabel.appendChild(document.createTextNode("For Mote Type " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + ":"));
            moteTypeLabel.classList.add("text1");
            tdMote.appendChild(moteTypeLabel);
            trMoteType.appendChild(tdMote);
            addFilesTable.appendChild(trMoteType);
            
            var tr = document.createElement("tr");
                
            //label file td
            var tdLabel = document.createElement("td");
            
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Add File(s): "));
            labelFile.classList.add("text1");
            
            var required = document.createElement("abbr");
            required.appendChild(document.createTextNode("*"));
            required.title = "required";
            labelFile.appendChild(required);
            tdLabel.appendChild(labelFile);
            
            tr.appendChild(tdLabel);
            
            if(add == 0) {
                var trOldFiles = document.createElement("tr");

                //label file td
                var tdLabel = document.createElement("td");
                var labelFile = document.createElement("label");
                labelFile.appendChild(document.createTextNode("Old File(s): "));
                labelFile.classList.add("text1");
                tdLabel.appendChild(labelFile);

                //old files td
                var tdSelect = document.createElement("td");
                var select = document.createElement("select");
                select.classList.add("text1");
                select.id = moteTypesList.options[moteTypesList.selectedIndex].value + "@OldFilesList";
                select.size = "5";
                jQuery(select).attr('multiple', 'multiple');
                //file select
                var moteTypeID = moteTypesList.options[moteTypesList.selectedIndex].value;
                var oldFileID = data.getAll("oldFileID" + moteTypeID + "[]");
                var oldFileName = data.getAll("oldFileName" + moteTypeID + "[]");
                for(var k = 0; k < oldFileID.length; k++) {
                    var option = document.createElement("option"); option.appendChild(document.createTextNode(oldFileName[k]));
                    option.value = oldFileID[k];
                    select.appendChild(option);
                }
                tdSelect.appendChild(select);

                //delete button td
                var tdDeleteButton = document.createElement("td");
                tdDeleteButton.style.verticalAlign = "bottom";
                var deleteBtn = document.createElement("input");
                deleteBtn.classList.add("button");
                deleteBtn.type = "button";
                deleteBtn.title = "Delete selected file(s)";
                deleteBtn.id = moteTypesList.options[moteTypesList.selectedIndex].value + "@deleteFile";
                deleteBtn.onclick = deleteSelectedFile;
                deleteBtn.value = "Delete Files";
                tdDeleteButton.appendChild(deleteBtn);


                trOldFiles.appendChild(tdLabel);
                trOldFiles.appendChild(tdSelect);
                trOldFiles.appendChild(tdDeleteButton);

                addFilesTable.appendChild(trOldFiles);
            }

            //input file td
            var tdFile = document.createElement("td");
            
            var inputFile = document.createElement("input");
            inputFile.type = "file";
            inputFile.classList.add("text1");
            jQuery(inputFile).attr('multiple', 'multiple');
            inputFile.id = moteTypesList.options[moteTypesList.selectedIndex].value + "@inputFile";
            tdFile.appendChild(inputFile);
            
            tr.appendChild(tdFile);

            addFilesTable.appendChild(tr);
        }
    }
}

function  dcube_select_changed() {
    var moteTypesList = document.getElementById("moteTypesList");
    var telosb_addFilesTable = document.getElementById("add_job_telosb_table").getElementsByTagName('tbody')[0];
    telosb_addFilesTable.innerHTML = "";
    
    var dcube_select = document.getElementById("dcube_select");

    if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_yes"){
        dcube_included = 1;
        //label file td
        var tr = document.createElement("tr");
        var tdLabel = document.createElement("td");
        var labelFile = document.createElement("label");
        labelFile.appendChild(document.createTextNode("Add File(s) for TelosB: "));
        labelFile.classList.add("text1");
        var required = document.createElement("abbr");
        required.appendChild(document.createTextNode("*"));
        required.title = "required";
        labelFile.appendChild(required);
        tdLabel.appendChild(labelFile);
        tr.appendChild(tdLabel);
        
        if(add == 0) {
            var trOldFiles = document.createElement("tr");

            //label file td
            var tdLabel = document.createElement("td");
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Old TelosB File(s): "));
            labelFile.classList.add("text1");
            tdLabel.appendChild(labelFile);

            //old files td
            var tdSelect = document.createElement("td");
            var select = document.createElement("select");
            select.classList.add("text1");
            select.id = moteTypesList.options[telosb_index].value + "@OldFilesList";
            select.size = "5";
            jQuery(select).attr('multiple', 'multiple');
            //file select
            var moteTypeID = moteTypesList.options[telosb_index].value;
            var oldFileID = data.getAll("oldFileID" + moteTypeID + "[]");
            var oldFileName = data.getAll("oldFileName" + moteTypeID + "[]");
            for(var k = 0; k < oldFileID.length; k++) {
                var option = document.createElement("option"); option.appendChild(document.createTextNode(oldFileName[k]));
                option.value = oldFileID[k];
                select.appendChild(option);
            }
            tdSelect.appendChild(select);

            //delete button td
            var tdDeleteButton = document.createElement("td");
            tdDeleteButton.style.verticalAlign = "bottom";
            var deleteBtn = document.createElement("input");
            deleteBtn.classList.add("button");
            deleteBtn.type = "button";
            deleteBtn.title = "Delete selected file(s)";
            deleteBtn.id = moteTypesList.options[telosb_index].value + "@deleteFile";
            deleteBtn.onclick = deleteSelectedFile;
            deleteBtn.value = "Delete Files";
            tdDeleteButton.appendChild(deleteBtn);


            trOldFiles.appendChild(tdLabel);
            trOldFiles.appendChild(tdSelect);
            trOldFiles.appendChild(tdDeleteButton);

            telosb_addFilesTable.appendChild(trOldFiles);
        }

        //input file td
        var tdFile = document.createElement("td");
        
        var inputFile = document.createElement("input");
        inputFile.type = "file";
        inputFile.classList.add("text1");
        jQuery(inputFile).attr('multiple', 'multiple');
        inputFile.id = moteTypesList.options[telosb_index].value + "@inputFile";
        tdFile.appendChild(inputFile);
        
        tr.appendChild(tdFile);

        telosb_addFilesTable.appendChild(tr);

        // *********************************************************************************************************** //
        // DCube file
        //label file td
        var tr = document.createElement("tr");
        var tdLabel = document.createElement("td");
        var labelFile = document.createElement("label");
        labelFile.appendChild(document.createTextNode("Add File for DCube Nodes: "));
        labelFile.classList.add("text1");
        var required = document.createElement("abbr");
        required.appendChild(document.createTextNode("*"));
        required.title = "required";
        labelFile.appendChild(required);
        tdLabel.appendChild(labelFile);
        tr.appendChild(tdLabel);
        
        if(add == 0 && data.get("dcube") != 0) {
            var trOldFiles = document.createElement("tr");

            //label file td
            var tdLabel = document.createElement("td");
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Old DCube File: "));
            labelFile.classList.add("text1");
            tdLabel.appendChild(labelFile);

            //old files td
            var tdSelect = document.createElement("td");
            var select = document.createElement("select");
            select.classList.add("text1");
            select.id = "OldFilesList@dcube";
            select.size = "2";
            //file select
            var option = document.createElement("option"); option.appendChild(document.createTextNode(data.get("dcube_oldFileName")));
            option.value = data.get("dcube_oldFileID");
            select.appendChild(option);
            select.value = option.value;
            tdSelect.appendChild(select);

            //delete button td
            var tdDeleteButton = document.createElement("td");
            tdDeleteButton.style.verticalAlign = "bottom";
            var deleteBtn = document.createElement("input");
            deleteBtn.classList.add("button");
            deleteBtn.type = "button";
            deleteBtn.title = "Delete selected file";
            deleteBtn.id = moteTypesList.options[telosb_index].value + "@deleteFile@dcube";
            deleteBtn.onclick = deleteSelectedDcubeFile;
            deleteBtn.value = "Delete File";
            tdDeleteButton.appendChild(deleteBtn);


            trOldFiles.appendChild(tdLabel);
            trOldFiles.appendChild(tdSelect);
            trOldFiles.appendChild(tdDeleteButton);

            telosb_addFilesTable.appendChild(trOldFiles);
        }

        //input file td
        var tdFile = document.createElement("td");
        
        var inputFile = document.createElement("input");
        inputFile.type = "file";
        inputFile.classList.add("text1");
        inputFile.id = "inputFile@dcube";
        tdFile.appendChild(inputFile);
        
        tr.appendChild(tdFile);

        telosb_addFilesTable.appendChild(tr);

    } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_no"){
        dcube_included = 0;
        //label file td
        var tr = document.createElement("tr");
        var tdLabel = document.createElement("td");
        var labelFile = document.createElement("label");
        labelFile.appendChild(document.createTextNode("Add File(s) for TelosB: "));
        labelFile.classList.add("text1");
        var required = document.createElement("abbr");
        required.appendChild(document.createTextNode("*"));
        required.title = "required";
        labelFile.appendChild(required);
        tdLabel.appendChild(labelFile);
        tr.appendChild(tdLabel);
        
        if(add == 0) {
            var trOldFiles = document.createElement("tr");

            //label file td
            var tdLabel = document.createElement("td");
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Old File(s): "));
            labelFile.classList.add("text1");
            tdLabel.appendChild(labelFile);

            //old files td
            var tdSelect = document.createElement("td");
            var select = document.createElement("select");
            select.classList.add("text1");
            select.id = moteTypesList.options[telosb_index].value + "@OldFilesList";
            select.size = "5";
            jQuery(select).attr('multiple', 'multiple');
            //file select
            var moteTypeID = moteTypesList.options[telosb_index].value;
            var oldFileID = data.getAll("oldFileID" + moteTypeID + "[]");
            var oldFileName = data.getAll("oldFileName" + moteTypeID + "[]");
            for(var k = 0; k < oldFileID.length; k++) {                
                var option = document.createElement("option"); option.appendChild(document.createTextNode(oldFileName[k]));
                option.value = oldFileID[k];
                select.appendChild(option);                
            }
            tdSelect.appendChild(select);

            //delete button td
            var tdDeleteButton = document.createElement("td");
            tdDeleteButton.style.verticalAlign = "bottom";
            var deleteBtn = document.createElement("input");
            deleteBtn.classList.add("button");
            deleteBtn.type = "button";
            deleteBtn.title = "Delete selected file(s)";
            deleteBtn.id = moteTypesList.options[telosb_index].value + "@deleteFile";
            deleteBtn.onclick = deleteSelectedFile;
            deleteBtn.value = "Delete Files";
            tdDeleteButton.appendChild(deleteBtn);


            trOldFiles.appendChild(tdLabel);
            trOldFiles.appendChild(tdSelect);
            trOldFiles.appendChild(tdDeleteButton);

            telosb_addFilesTable.appendChild(trOldFiles);
        }

        //input file td
        var tdFile = document.createElement("td");
        
        var inputFile = document.createElement("input");
        inputFile.type = "file";
        inputFile.classList.add("text1");
        jQuery(inputFile).attr('multiple', 'multiple');
        inputFile.id = moteTypesList.options[telosb_index].value + "@inputFile";
        tdFile.appendChild(inputFile);
        
        tr.appendChild(tdFile);

        telosb_addFilesTable.appendChild(tr);
    } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_only"){
        dcube_included = 1;
        // DCube file
        //label file td
        var tr = document.createElement("tr");
        var tdLabel = document.createElement("td");
        var labelFile = document.createElement("label");
        labelFile.appendChild(document.createTextNode("Add File for DCube Nodes: "));
        labelFile.classList.add("text1");
        var required = document.createElement("abbr");
        required.appendChild(document.createTextNode("*"));
        required.title = "required";
        labelFile.appendChild(required);
        tdLabel.appendChild(labelFile);
        tr.appendChild(tdLabel);
        
        if(add == 0 && data.get("dcube") != 0) {
            var trOldFiles = document.createElement("tr");

            //label file td
            var tdLabel = document.createElement("td");
            var labelFile = document.createElement("label");
            labelFile.appendChild(document.createTextNode("Old DCube File: "));
            labelFile.classList.add("text1");
            tdLabel.appendChild(labelFile);

            //old files td
            var tdSelect = document.createElement("td");
            var select = document.createElement("select");
            select.classList.add("text1");
            select.id = "OldFilesList@dcube";
            select.size = "2";
            //file select
            var option = document.createElement("option"); option.appendChild(document.createTextNode(data.get("dcube_oldFileName")));
            option.value = data.get("dcube_oldFileID");
            select.appendChild(option);
            select.value = option.value;
            tdSelect.appendChild(select);

            //delete button td
            var tdDeleteButton = document.createElement("td");
            tdDeleteButton.style.verticalAlign = "bottom";
            var deleteBtn = document.createElement("input");
            deleteBtn.classList.add("button");
            deleteBtn.type = "button";
            deleteBtn.title = "Delete selected file";
            deleteBtn.id = moteTypesList.options[telosb_index].value + "@deleteFile@dcube";
            deleteBtn.onclick = deleteSelectedDcubeFile;
            deleteBtn.value = "Delete File";
            tdDeleteButton.appendChild(deleteBtn);


            trOldFiles.appendChild(tdLabel);
            trOldFiles.appendChild(tdSelect);
            trOldFiles.appendChild(tdDeleteButton);

            telosb_addFilesTable.appendChild(trOldFiles);
        }

        //input file td
        var tdFile = document.createElement("td");
        
        var inputFile = document.createElement("input");
        inputFile.type = "file";
        inputFile.classList.add("text1");
        inputFile.id = "inputFile@dcube";
        tdFile.appendChild(inputFile);
        
        tr.appendChild(tdFile);

        telosb_addFilesTable.appendChild(tr);
    }
}

function nextAddJobDB() {
    //check job name
    var jobNametxt = document.getElementById("jobNametxt");
    var moteTypesList = document.getElementById("moteTypesList");
    
    if(jobNametxt.value == "" || jobNametxt.value == null){
        alert("Please, enter the job name!");
        return false;
    } else{
        //check select mote type
        if(moteTypesList.selectedIndex == 0){
            alert("Please, select a mote type!");
            return false;
        } else {
            data = new FormData();
            data.append('userID', userID);
            data.append('jobName', jobNametxt.value);
            //check choosen file(s)
            if(moteTypesList.options[moteTypesList.selectedIndex].value == -1){
                //more than one mote type
                data.append('numberOfMoteTypes', (moteTypesList.length - 2));
                
                for(i = 1; i < moteTypesList.length - 1; i++) {
                    if(dcube && moteTypesList.options[i].innerHTML == "telosb"){
                        var dcube_select = document.getElementById("dcube_select");
                        data.append('dcube_included', dcube_select.options[dcube_select.selectedIndex].value);
                        // check dcube included option
                        if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_yes"){
                            var fileInput = document.getElementById(moteTypesList.options[i].value + "@inputFile");
                            if(fileInput.files.length == 0){
                                alert("Please, select file(s) for " + moteTypesList.options[i].innerHTML + " mote type!");
                                return false;
                            } else{
                                var size_is_ok = 1;
                                var length_is_ok = 1;
                                for(j = 0; j < fileInput.files.length; j++) {
                                    if(fileInput.files[j].size > max_file_size){
                                        size_is_ok = 0;
                                        break;
                                    }

                                    if(fileInput.files[j].name.length > max_file_name_length){
                                        length_is_ok = 0;
                                        break;
                                    }
                                }

                                if(size_is_ok == 1 && length_is_ok == 1) {
                                    //add the job to the DB with multiple mote types and multiple files
                                    data.append('numberOfFiles' + (i - 1), fileInput.files.length);
                                    data.append('moteTypeName' + (i - 1), moteTypesList.options[i].text);
                                    data.append('moteTypeID' + (i - 1), moteTypesList.options[i].value);
                                    
                                    for(j = 0; j < fileInput.files.length; j++) {
                                        data.append('fileName' + (i - 1) + "" + j, fileInput.files.item(j).name);
                                    
                                        var file = fileInput.files[j];
                                        data.append('file' + (i - 1) + "" + j, file, file.name);
                                    }
                                } else {
                                    if(size_is_ok == 0) {
                                        alert("Error, max file size is " + max_file_size/1024 + " KB");
                                        return false;
                                    }
                                    if(length_is_ok == 0) {
                                        alert("Error, max file name length is " + max_file_name_length + " characters");
                                        return false;
                                    }
                                }
                            }

                            // dcube file
                            var fileInput = document.getElementById("inputFile@dcube");
                            if(fileInput.files.length == 0){
                                alert("Please, select file for " + moteTypesList.options[i].innerHTML + " mote type for DCube nodes!");
                                return false;
                            } else{
                                var size_is_ok = 1;
                                var length_is_ok = 1;
                                for(j = 0; j < fileInput.files.length; j++) {
                                    if(fileInput.files[j].size > max_file_size){
                                        size_is_ok = 0;
                                        break;
                                    }

                                    if(fileInput.files[j].name.length > max_file_name_length){
                                        length_is_ok = 0;
                                        break;
                                    }
                                }

                                if(size_is_ok == 1 && length_is_ok == 1) {
                                    //add the job to the DB with multiple mote types and multiple files                                    
                                    for(j = 0; j < fileInput.files.length; j++) {
                                        data.append('dcube_fileName', fileInput.files.item(j).name);
                                    
                                        var file = fileInput.files[j];
                                        data.append('dcube_file', file, file.name);

                                        data.append('dcube_moteTypeID', moteTypesList.options[i].value);
                                    }
                                } else {
                                    if(size_is_ok == 0) {
                                        alert("Error, max file size is " + max_file_size/1024 + " KB");
                                        return false;
                                    }
                                    if(length_is_ok == 0) {
                                        alert("Error, max file name length is " + max_file_name_length + " characters");
                                        return false;
                                    }
                                }
                            }
                        } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_no"){
                            var fileInput = document.getElementById(moteTypesList.options[i].value + "@inputFile");
                            if(fileInput.files.length == 0){
                                alert("Please, select file(s) for " + moteTypesList.options[i].innerHTML + " mote type!");
                                return false;
                            } else{
                                var size_is_ok = 1;
                                var length_is_ok = 1;
                                for(j = 0; j < fileInput.files.length; j++) {
                                    if(fileInput.files[j].size > max_file_size){
                                        size_is_ok = 0;
                                        break;
                                    }

                                    if(fileInput.files[j].name.length > max_file_name_length){
                                        length_is_ok = 0;
                                        break;
                                    }
                                }

                                if(size_is_ok == 1 && length_is_ok == 1) {
                                    //add the job to the DB with multiple mote types and multiple files
                                    data.append('numberOfFiles' + (i - 1), fileInput.files.length);
                                    data.append('moteTypeName' + (i - 1), moteTypesList.options[i].text);
                                    data.append('moteTypeID' + (i - 1), moteTypesList.options[i].value);
                                    
                                    for(j = 0; j < fileInput.files.length; j++) {
                                        data.append('fileName' + (i - 1) + "" + j, fileInput.files.item(j).name);
                                    
                                        var file = fileInput.files[j];
                                        data.append('file' + (i - 1) + "" + j, file, file.name);
                                    }
                                } else {
                                    if(size_is_ok == 0) {
                                        alert("Error, max file size is " + max_file_size/1024 + " KB");
                                        return false;
                                    }
                                    if(length_is_ok == 0) {
                                        alert("Error, max file name length is " + max_file_name_length + " characters");
                                        return false;
                                    }
                                }
                            }
                        } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_only"){
                            // dcube file
                            var fileInput = document.getElementById("inputFile@dcube");
                            if(fileInput.files.length == 0){
                                alert("Please, select file for " + moteTypesList.options[i].innerHTML + " mote type for DCube nodes!");
                                return false;
                            } else{
                                var size_is_ok = 1;
                                var length_is_ok = 1;
                                for(j = 0; j < fileInput.files.length; j++) {
                                    if(fileInput.files[j].size > max_file_size){
                                        size_is_ok = 0;
                                        break;
                                    }

                                    if(fileInput.files[j].name.length > max_file_name_length){
                                        length_is_ok = 0;
                                        break;
                                    }
                                }

                                data.append('numberOfFiles' + (i - 1), 0);

                                if(size_is_ok == 1 && length_is_ok == 1) {
                                    //add the job to the DB with multiple mote types and multiple files                                    
                                    for(j = 0; j < fileInput.files.length; j++) {
                                        data.append('dcube_fileName', fileInput.files.item(j).name);
                                    
                                        var file = fileInput.files[j];
                                        data.append('dcube_file', file, file.name);

                                        data.append('dcube_moteTypeID', moteTypesList.options[i].value);
                                    }
                                } else {
                                    if(size_is_ok == 0) {
                                        alert("Error, max file size is " + max_file_size/1024 + " KB");
                                        return false;
                                    }
                                    if(length_is_ok == 0) {
                                        alert("Error, max file name length is " + max_file_name_length + " characters");
                                        return false;
                                    }
                                }
                            }
                        }
                    } else{
                        var fileInput = document.getElementById(moteTypesList.options[i].value + "@inputFile");
                        if(fileInput.files.length == 0){
                            alert("Please, select file(s) for " + moteTypesList.options[i].innerHTML + " mote type!");
                            return false;
                        } else{
                            var size_is_ok = 1;
                            var length_is_ok = 1;
                            for(j = 0; j < fileInput.files.length; j++) {
                                if(fileInput.files[j].size > max_file_size){
                                    size_is_ok = 0;
                                    break;
                                }

                                if(fileInput.files[j].name.length > max_file_name_length){
                                    length_is_ok = 0;
                                    break;
                                }
                            }

                            if(size_is_ok == 1 && length_is_ok == 1) {
                                //add the job to the DB with multiple mote types and multiple files
                                data.append('numberOfFiles' + (i - 1), fileInput.files.length);
                                data.append('moteTypeName' + (i - 1), moteTypesList.options[i].text);
                                data.append('moteTypeID' + (i - 1), moteTypesList.options[i].value);
                                
                                for(j = 0; j < fileInput.files.length; j++) {
                                    data.append('fileName' + (i - 1) + "" + j, fileInput.files.item(j).name);
                                
                                    var file = fileInput.files[j];
                                    data.append('file' + (i - 1) + "" + j, file, file.name);
                                }
                            } else {
                                if(size_is_ok == 0) {
                                    alert("Error, max file size is " + max_file_size/1024 + " KB");
                                    return false;
                                }
                                if(length_is_ok == 0) {
                                    alert("Error, max file name length is " + max_file_name_length + " characters");
                                    return false;
                                }
                            }
                        }
                    }
                }
            } else{
                //one mote type selected
                if(dcube && moteTypesList.options[moteTypesList.selectedIndex].innerHTML == "telosb"){
                    var dcube_select = document.getElementById("dcube_select");
                    data.append('dcube_included', dcube_select.options[dcube_select.selectedIndex].value);
                    // check dcube included option
                    var dcube_select = document.getElementById("dcube_select");
                    if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_yes"){
                        var fileInput = document.getElementById(moteTypesList.options[moteTypesList.selectedIndex].value + "@inputFile");
                    
                        if(fileInput.files.length == 0){
                            alert("Please, select file(s) for " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + " mote type!");
                            return false;
                        } else{
                            var size_is_ok = 1;
                            var length_is_ok = 1;
                            for(j = 0; j < fileInput.files.length; j++) {
                                if(fileInput.files[j].size > max_file_size){
                                    size_is_ok = 0;
                                    break;
                                }

                                if(fileInput.files[j].name.length > max_file_name_length){
                                    length_is_ok = 0;
                                    break;
                                }
                            }

                            if(size_is_ok == 1 && length_is_ok == 1) {
                                //add the job to the DB with one mote type and one file
                                data.append('numberOfMoteTypes', 1);
                                
                                data.append('numberOfFiles0', fileInput.files.length);
                                
                                data.append('moteTypeName0', moteTypesList.options[moteTypesList.selectedIndex].text);
                                
                                data.append('moteTypeID0', moteTypesList.options[moteTypesList.selectedIndex].value);
                                
                                for(j = 0; j < fileInput.files.length; j++) {
                                    data.append('fileName0' + j, fileInput.files.item(j).name);

                                    var file = fileInput.files[j];
                                    data.append('file0' + j, file, file.name);
                                }
                            } else {
                                if(size_is_ok == 0) {
                                    alert("Error, max file size is " + max_file_size/1024 + " KB");
                                    return false;
                                }
                                if(length_is_ok == 0) {
                                    alert("Error, max file name length is " + max_file_name_length + " characters");
                                    return false;
                                }
                            }
                        }

                        // dcube file
                        var fileInput = document.getElementById("inputFile@dcube");
                    
                        if(fileInput.files.length == 0){
                            alert("Please, select file for " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + " mote type for DCube nodes!");
                            return false;
                        } else{
                            var size_is_ok = 1;
                            var length_is_ok = 1;
                            for(j = 0; j < fileInput.files.length; j++) {
                                if(fileInput.files[j].size > max_file_size){
                                    size_is_ok = 0;
                                    break;
                                }

                                if(fileInput.files[j].name.length > max_file_name_length){
                                    length_is_ok = 0;
                                    break;
                                }
                            }

                            if(size_is_ok == 1 && length_is_ok == 1) {
                                //add the job to the DB with one mote type and one file                                
                                for(j = 0; j < fileInput.files.length; j++) {
                                    data.append('dcube_fileName', fileInput.files.item(j).name);

                                    var file = fileInput.files[j];
                                    data.append('dcube_file', file, file.name);

                                    data.append('dcube_moteTypeID', moteTypesList.options[moteTypesList.selectedIndex].value);
                                }
                            } else {
                                if(size_is_ok == 0) {
                                    alert("Error, max file size is " + max_file_size/1024 + " KB");
                                    return false;
                                }
                                if(length_is_ok == 0) {
                                    alert("Error, max file name length is " + max_file_name_length + " characters");
                                    return false;
                                }
                            }
                        }
                    } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_no"){
                        var fileInput = document.getElementById(moteTypesList.options[moteTypesList.selectedIndex].value + "@inputFile");
                    
                        if(fileInput.files.length == 0){
                            alert("Please, select file(s) for " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + " mote type!");
                            return false;
                        } else{
                            var size_is_ok = 1;
                            var length_is_ok = 1;
                            for(j = 0; j < fileInput.files.length; j++) {
                                if(fileInput.files[j].size > max_file_size){
                                    size_is_ok = 0;
                                    break;
                                }

                                if(fileInput.files[j].name.length > max_file_name_length){
                                    length_is_ok = 0;
                                    break;
                                }
                            }

                            if(size_is_ok == 1 && length_is_ok == 1) {
                                //add the job to the DB with one mote type and one file
                                data.append('numberOfMoteTypes', 1);
                                
                                data.append('numberOfFiles0', fileInput.files.length);
                                
                                data.append('moteTypeName0', moteTypesList.options[moteTypesList.selectedIndex].text);
                                
                                data.append('moteTypeID0', moteTypesList.options[moteTypesList.selectedIndex].value);
                                
                                for(j = 0; j < fileInput.files.length; j++) {
                                    data.append('fileName0' + j, fileInput.files.item(j).name);

                                    var file = fileInput.files[j];
                                    data.append('file0' + j, file, file.name);
                                }
                            } else {
                                if(size_is_ok == 0) {
                                    alert("Error, max file size is " + max_file_size/1024 + " KB");
                                    return false;
                                }
                                if(length_is_ok == 0) {
                                    alert("Error, max file name length is " + max_file_name_length + " characters");
                                    return false;
                                }
                            }
                        }
                    } else if(dcube_select.options[dcube_select.selectedIndex].value == "dcube_only"){
                        // dcube file
                        var fileInput = document.getElementById("inputFile@dcube");
                    
                        if(fileInput.files.length == 0){
                            alert("Please, select file for " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + " mote type for DCube nodes!");
                            return false;
                        } else{
                            var size_is_ok = 1;
                            var length_is_ok = 1;
                            for(j = 0; j < fileInput.files.length; j++) {
                                if(fileInput.files[j].size > max_file_size){
                                    size_is_ok = 0;
                                    break;
                                }

                                if(fileInput.files[j].name.length > max_file_name_length){
                                    length_is_ok = 0;
                                    break;
                                }
                            }

                            data.append('numberOfMoteTypes', 1);
                            data.append('numberOfFiles0', 0);

                            if(size_is_ok == 1 && length_is_ok == 1) {
                                //add the job to the DB with one mote type and one file                                
                                for(j = 0; j < fileInput.files.length; j++) {
                                    data.append('dcube_fileName', fileInput.files.item(j).name);

                                    var file = fileInput.files[j];
                                    data.append('dcube_file', file, file.name);
                                    data.append('dcube_moteTypeID', moteTypesList.options[moteTypesList.selectedIndex].value);
                                }
                            } else {
                                if(size_is_ok == 0) {
                                    alert("Error, max file size is " + max_file_size/1024 + " KB");
                                    return false;
                                }
                                if(length_is_ok == 0) {
                                    alert("Error, max file name length is " + max_file_name_length + " characters");
                                    return false;
                                }
                            }
                        }
                    }
                } else{
                    var fileInput = document.getElementById(moteTypesList.options[moteTypesList.selectedIndex].value + "@inputFile");
                    
                    if(fileInput.files.length == 0){
                        alert("Please, select file(s) for " + moteTypesList.options[moteTypesList.selectedIndex].innerHTML + " mote type!");
                        return false;
                    } else{
                        var size_is_ok = 1;
                        var length_is_ok = 1;
                        for(j = 0; j < fileInput.files.length; j++) {
                            if(fileInput.files[j].size > max_file_size){
                                size_is_ok = 0;
                                break;
                            }

                            if(fileInput.files[j].name.length > max_file_name_length){
                                length_is_ok = 0;
                                break;
                            }
                        }

                        if(size_is_ok == 1 && length_is_ok == 1) {
                            //add the job to the DB with one mote type and one file
                            data.append('numberOfMoteTypes', 1);
                            data.append('dcube_included', "dcube_no");
                            
                            data.append('numberOfFiles0', fileInput.files.length);
                            
                            data.append('moteTypeName0', moteTypesList.options[moteTypesList.selectedIndex].text);
                            
                            data.append('moteTypeID0', moteTypesList.options[moteTypesList.selectedIndex].value);
                            
                            for(j = 0; j < fileInput.files.length; j++) {
                                data.append('fileName0' + j, fileInput.files.item(j).name);

                                var file = fileInput.files[j];
                                data.append('file0' + j, file, file.name);
                            }
                        } else {
                            if(size_is_ok == 0) {
                                alert("Error, max file size is " + max_file_size/1024 + " KB");
                                return false;
                            }
                            if(length_is_ok == 0) {
                                alert("Error, max file name length is " + max_file_name_length + " characters");
                                return false;
                            }
                        }
                    }
                }
            }
            
            //data has job name, mote types, and files
            //assign each file to clusters and motes, then add to DB
            
            document.getElementById("associationAddJobButtons").style.display = "block";
            document.getElementById("associationUpdateJobButtons").style.display = "none";
            
            var jobName = data.get('jobName');
            document.getElementById("associationJobLegend").innerHTML = "Add Associations for \"" + jobName + "\" Job";
            document.getElementById("associationJobNameLabel").innerHTML = "Job name: " + jobName;
            
            fillassociationMoteTypesList();
            
            /*document.getElementById("scheduleLater").checked = true;
            document.getElementById("scheduleSoon").checked = true;
            document.getElementById("scheduleJob").style.display = "none";
            document.getElementById("scheduledDateTime").style.display = "none";
            document.getElementById("scheduledDateTimeLabel").style.display = "none";
            document.getElementById("scheduledDateTimeNoteLabel").style.display = "none";
            if(quota - usedQuota < 5) {
                $("#scheduleNow").attr("disabled", true).on('click');
                document.getElementById("scheduleResultLabel").style.display = "block";
            } else {
                $("#scheduleNow").attr("disabled", false).on('click');
                document.getElementById("scheduleResultLabel").style.display = "none";
                //set max duration
                document.getElementById("durationJob").max = quota - usedQuota;
            }*/
            
            var addJobDiv = document.getElementById("addJobDiv");
            jQuery(addJobDiv).toggle('slow');

            var associationJobDiv = document.getElementById("associationJobDiv");
            jQuery(associationJobDiv).toggle('slow');
        }
    }
}

function backJob() {
    var addJobDiv = document.getElementById("addJobDiv");
    jQuery(addJobDiv).toggle('slow');

    var associationJobDiv = document.getElementById("associationJobDiv");
    jQuery(associationJobDiv).toggle('slow');
}

function addJobDB() {
    //check for association (at least one file per mote type)
    var moteAdded = [];
    for (var i = 0; i < data.get('numberOfMoteTypes'); i++){
        moteAdded[i] = 0;
        for(var j = 0; j < data.get('numberOfFiles' + i); j++) {
            if(data.has("motes" + i + '' + j + "[]")) {
                moteAdded[i]++;
            }
        }
    }
    
    var ok = 1;
    for(var i = 0; i < moteAdded.length; i++) {
        if(moteAdded[i] < data.get('numberOfFiles' + i)) {
            ok = 0;
            alert("Kindly, assiciate all uploaded files with motes for mote type " + data.get('moteTypeName' + i));
            break;
        }
    }
    
    //send data form to php in xmlhttp to save to DB and show jobs table
    if(ok) {
        //check if schedule! add to data form duration and start timestamp
        /*if(document.getElementById("scheduleLater").checked == true) {
            data.append("scheduleLater", 1);
        } else {
            data.append("scheduleLater", 0);
            data.append("duration", document.getElementById("durationJob").value);
            if(document.getElementById("scheduleSoon").checked == true)
                updateSchedule();
            data.append("startTimestamp", document.getElementById("scheduledDateTime").value);
        }*/
        
        document.getElementById("errorAddJob").style.display = "none";
        document.getElementById("errorAddJobUnsupportedFile").style.display = "none";
        document.getElementById("unsupportedFiles").innerHTML = "";
        document.getElementById("successAddJob").style.display = "none";
        
        document.getElementById("uploadingAddJob").style.display = "block";
        document.getElementById("addJobModal").style.display = "block";
        
        var xhr = new XMLHttpRequest();
        
        xhr.open('POST', 'php/addJob.php', true);
        xhr.send(data);
        xhr.onload = function () {
            if (xhr.status === 200) {
                var myObj = JSON.parse(this.responseText);
               
                document.getElementById("uploadingAddJob").style.display = "none";
                
                if(myObj.status == "SUCCESS") {
                    addedJobID = myObj.jobID;
                    var btn = document.getElementById("btnScheduleNowJobAddJob");
                    document.getElementById("successAddJob").style.display = "block";
                } else {
                    if(myObj.message == "unsuported file format"){
                        var container = document.getElementById("unsupportedFiles");
                        container.append(JSON.stringify(myObj.files));
                        document.getElementById("errorAddJobUnsupportedFile").style.display = "block";
                    }
                    else
                        document.getElementById("errorAddJob").style.display = "block";
                }
            }
        };
    }
}

function fillassociationMoteTypesList() {
    var associationMoteTypesList = document.getElementById("associationMoteTypesList");
    associationMoteTypesList.innerHTML = "";
    
    for(var i = 0; i < data.get('numberOfMoteTypes'); i++) {
        var option = document.createElement("option"); option.appendChild(document.createTextNode(data.get('moteTypeName' + i)));
        option.value = data.get('moteTypeID' + i);
        associationMoteTypesList.appendChild(option);
    }        
    associationMoteTypesList.value = data.get('moteTypeID0');
    associationMoteTypesList.onchange();
}

function associationMoteTypeSelected() {    
    refreshClustersMotes();
    refreshAssociationTable();
}

function refreshClustersMotes() {
    var associationMoteTypesList = document.getElementById("associationMoteTypesList");
    var selectedMoteTypeID = associationMoteTypesList.options[associationMoteTypesList.selectedIndex].value;
    
    //get all clusters and motes for the selected mote type from xml which are not in data!
    
    //check if these motes and clusters are not selected for other files
    
    var clustersUL = document.getElementById("clustersUL");
    clustersUL.innerHTML = "";
    
    var selectAllLI = document.createElement("li");
        
    var label = document.createElement("label");
    label.for = "ckeckAll";

    var check = document.createElement("input");
    check.type = "checkbox";
    check.id = "selectAll";
    check.onclick = selectAllClicked;

    label.appendChild(check);
    label.appendChild(document.createTextNode("Select All"));
    
    selectAllLI.appendChild(label);
    var selectAllAdded = 0;
    //console.log(motesInfoXMLDoc);
    //for each cluster, add cluster
    for(var i = 0; i < motesInfoXMLDoc.getElementsByTagName("clusters")[0].childNodes.length; i++) {
        
            var clusterID = motesInfoXMLDoc.getElementsByTagName("clusterID")[i].childNodes[0].nodeValue;
            var clusterName = motesInfoXMLDoc.getElementsByTagName("clusterName")[i].childNodes[0].nodeValue;
            var floorLevel = motesInfoXMLDoc.getElementsByTagName("floorLevel")[i].childNodes[0].nodeValue;

            var li = document.createElement("li");

            var label = document.createElement("label");
            label.for = clusterID + "@ckeckAll";

            var check = document.createElement("input");
            check.type = "checkbox";
            check.id = clusterID + "@ckeckAll";
            check.classList.add("clustersOption");
            check.onclick = checkAllClicked;

            var a = document.createElement("a");
            a.appendChild(document.createTextNode("+"));
            a.id = clusterID + "@a";
            a.classList.add("expand");
            a.onclick = toggleCluster;

            label.appendChild(check);
            label.appendChild(document.createTextNode(clusterName + " at floor level: " + floorLevel));

            li.appendChild(a);
            li.appendChild(label);

            //for each cluster, add motes in this cluster
            var motesUL = document.createElement("ul");
            motesUL.classList.add("motesUL");
            motesUL.classList.add("text1");

            var clusterHasMoteType = 0;
            for(var j = 0; j < motesInfoXMLDoc.getElementsByTagName("motes")[0].childNodes.length; j++) {
                var clusters_clusterID = motesInfoXMLDoc.getElementsByTagName("clusters_clusterID")[j].childNodes[0].nodeValue;

                var moteTypes_moteTypeID = motesInfoXMLDoc.getElementsByTagName("moteTypes_moteTypeID")[j].childNodes[0].nodeValue;
                
                var status = motesInfoXMLDoc.getElementsByTagName("status")[j].childNodes[0].nodeValue;

                if(status == 1 && clusters_clusterID == clusterID) {
                    if(moteTypes_moteTypeID == selectedMoteTypeID) {
                        var moteID = motesInfoXMLDoc.getElementsByTagName("moteID")[j].childNodes[0].nodeValue;

                        if(moteUsed(moteID) == 0) {
                            //never firget to change it to ==
                            if(status == 1) {
                                if(clusterHasMoteType == 0)
                                    clusterHasMoteType = 1;

                                var virtual_id = motesInfoXMLDoc.getElementsByTagName("virtual_id")[j].childNodes[0].nodeValue;

                                var coordinates = motesInfoXMLDoc.getElementsByTagName("coordinates")[j].childNodes[0].nodeValue;

                                var liOption = document.createElement("li");

                                var label = document.createElement("label");
                                label.classList.add("label" + clusterID);

                                var check = document.createElement("input");
                                check.type = "checkbox";
                                check.classList.add("subOption" + clusterID);
                                check.id = clusterID + "@" + moteID + "@check";
                                check.onclick = checkOneClicked;

                                label.appendChild(check);
                                label.appendChild(document.createTextNode("Mote id " + virtual_id + " at coordinates: " + coordinates));

                                liOption.appendChild(label);
                                motesUL.appendChild(liOption);

                                label.style.display = "none";
                                check.style.display = "none"; 
                            }
                        }
                    }
                }
            }

            li.appendChild(motesUL);

            if(clusterHasMoteType == 1){
                if(selectAllAdded == 0){
                    selectAllAdded = 1;
                    clustersUL.appendChild(selectAllLI);
                }
                clustersUL.appendChild(li);
            }
        
    }
    
    if(clustersUL.getElementsByTagName("li").length == 0){
        document.getElementById("clustersListState").style.display = "block";
        document.getElementById("moteLabel").style.display = "none";
    }
    else {
        document.getElementById("clustersListState").style.display = "none";
        document.getElementById("moteLabel").style.display = "block";
    }
}

function moteUsed(moteID) {
    for(var i = 0; i < data.get("numberOfMoteTypes"); i++){
        
        //old files
        var motTypeID = data.get("moteTypeID" + i);
        var oldFileID = data.getAll("oldFileID" + motTypeID + "[]");
        for(var j = 0; j < oldFileID.length; j++) {
            var oldMotes = data.getAll("oldMotes" + oldFileID[j] + "[]");
            for(var k = 0; k < oldMotes.length; k++) {
                if(oldMotes[k] == moteID)
                    return 1;
            }
        }
        
        //new files
        for(var j = 0; j < data.get("numberOfFiles" + i); j++){
            if(data.has("motes" + i + "" + j + "[]")){
                var motes = data.getAll("motes" + i + "" + j + "[]");
                for(var k = 0; k < motes.length; k++){
                    if(motes[k] == moteID)
                        return 1;
                }
            }
        }
    }
    return 0;
}

function selectAllClicked(){
    var clustersCheckboxes = document.querySelectorAll('input.clustersOption');
    
    for(var i=0; i<clustersCheckboxes.length; i++) {
        clustersCheckboxes[i].checked = this.checked;
        
        var id = clustersCheckboxes[i].id.split("@");
        var checkboxes = document.querySelectorAll('input.subOption' + id[0]);
    
        for(var j=0; j<checkboxes.length; j++) {
            checkboxes[j].checked = this.checked;
        }
    }
}

function toggleCluster() {
    var id = this.id.split("@");
    
    if(this.innerHTML == "+")
        this.innerHTML = "-";
    else
        this.innerHTML = "+";
    
    var checkboxes = document.querySelectorAll('input.subOption' + id[0]);
    var labels = document.querySelectorAll('label.label' + id[0]);
    
    for(var i=0; i<checkboxes.length; i++) {
        jQuery(checkboxes[i]).toggle('fast');
        jQuery(labels[i]).toggle('fast');
        
        jQuery(checkboxes[i]).toggleClass("up");
        jQuery(labels[i]).toggleClass("up");
    }
}

function checkAllClicked() {
    var id = this.id.split("@");
    
    var checkboxes = document.querySelectorAll('input.subOption' + id[0]);
    
    for(var i=0; i<checkboxes.length; i++) {
        checkboxes[i].checked = this.checked;
    }
    
    var checkedCount = document.querySelectorAll('input.clustersOption:checked').length;
    var totalCount = document.querySelectorAll('input.clustersOption').length;
    var selectAll = document.getElementById('selectAll');
    selectAll.checked = (checkedCount == totalCount);
}

function checkOneClicked() {
    var id = this.id.split("@");
    
    var checkboxes = document.querySelectorAll('input.subOption' + id[0]);
    var checkall = document.getElementById(id[0] + '@ckeckAll');
    
    var checkedCount = document.querySelectorAll('input.subOption' + id[0] + ':checked').length;

    checkall.checked = checkedCount > 0;
    checkall.indeterminate = checkedCount > 0 && checkedCount < checkboxes.length;
    
    var checkedCount = document.querySelectorAll('input.clustersOption:checked').length;
    var totalCount = document.querySelectorAll('input.clustersOption').length;
    var selectAll = document.getElementById('selectAll');
    selectAll.checked = (checkedCount == totalCount);
}

function nextCancelJob() {
    var addJobDiv = document.getElementById("addJobDiv");
    jQuery(addJobDiv).toggle('slow');
    
    var jobsTableDiv = document.getElementById("jobsTableDiv");
    jQuery(jobsTableDiv).toggle('slow');
}

function cancelJob() {
    var associationJobDiv = document.getElementById("associationJobDiv");
    jQuery(associationJobDiv).toggle('slow');
    
    var jobsTableDiv = document.getElementById("jobsTableDiv");
    jQuery(jobsTableDiv).toggle('slow');
}

function addAssociation() {    
    //get selected file id
    var associationFilesList = document.getElementById("associationFilesList");
    
    var checkedMotes = 0;
    var clustersCheckboxes = document.querySelectorAll('input.clustersOption');
    for(var i=0; i<clustersCheckboxes.length; i++) {        
        var id = clustersCheckboxes[i].id.split("@");
        checkedMotes += document.querySelectorAll('input.subOption' + id[0] + ':checked').length;
    }
    
    //check for selected file and clusters/motes
    if((associationFilesList.selectedIndex == -1) || (checkedMotes == 0)){
        alert("Please, select file and clusters and/or motes.");
    } else {
        var fileInfo = associationFilesList.options[associationFilesList.selectedIndex].value;
        var fileID = fileInfo.split("@")[0];
        var fileType = fileInfo.split("@")[1];
    
        //get selected motes ids
        for(var i=0; i<clustersCheckboxes.length; i++) {        
            var id = clustersCheckboxes[i].id.split("@");
            var checkedMotes = document.querySelectorAll('input.subOption' + id[0] + ':checked');

            for(var j=0; j<checkedMotes.length; j++) {
                var moteID = checkedMotes[j].id.split("@")[1];
                
                if(fileType == "newFile")
                    data.append("motes" + fileID + "[]", moteID);
                else
                    data.append("oldMotes" + fileID + "[]", moteID);
            }
        }

        refreshClustersMotes();
        refreshAssociationTable();
    }
}

function refreshAssociationTable() {
    //delete files from flie list exists in data
    //add files to file list not exists in data
    var associationFilesList = document.getElementById("associationFilesList");
    associationFilesList.innerHTML = "";
    
    var associationMoteTypesList = document.getElementById("associationMoteTypesList");
    var selectedMoteTypeID = associationMoteTypesList.options[associationMoteTypesList.selectedIndex].value;
    
    for (var i = 0; i < data.get('numberOfMoteTypes'); i++){
        if(selectedMoteTypeID == data.get('moteTypeID' + i)){
            //add old files to list
            var motTypeID = data.get('moteTypeID' + i);
            var oldFileID = data.getAll("oldFileID" + motTypeID + "[]");
            var oldFileName = data.getAll("oldFileName" + motTypeID + "[]");
            for(var j = 0; j < oldFileID.length; j++) {
                if(!data.has("oldMotes" + oldFileID[j] + "[]")) {
                    var option = document.createElement("option"); option.appendChild(document.createTextNode(oldFileName[j]));
                    option.value = oldFileID[j] + "@oldFile";
                    associationFilesList.appendChild(option);
                }
            }
            
            //add new files to files list
            for(var j = 0; j < data.get('numberOfFiles' + i); j++) {
                //add to file list if not Associated in data
                if(!data.has("motes" + i + '' + j + "[]")) {
                    var option = document.createElement("option"); option.appendChild(document.createTextNode(data.get('fileName' + i + '' + j)));
                    option.value = i + '' + j + "@newFile";
                    associationFilesList.appendChild(option);
                }
            }
            break;
        }
    }
    
    //add all Associated files to association table
    var associationTablesContainer = document.getElementById("associationTablesContainer");
    associationTablesContainer.innerHTML = "";
    
    var div = document.createElement("div");
    div.classList.add("box-title");
    div.appendChild(document.createTextNode("Associated Files"));
    associationTablesContainer.appendChild(div);
    
    var br = document.createElement("br");
    
    for (var i = 0; i < data.get('numberOfMoteTypes'); i++){
        var moteAdded = 0;
        var table = null;
        var tableBody = null;
        //old files
        var motTypeID = data.get('moteTypeID' + i);
        var oldFileID = data.getAll("oldFileID" + motTypeID + "[]");
        var oldFileName = data.getAll("oldFileName" + motTypeID + "[]");
        for(var j = 0; j < oldFileID.length; j++) {
            if(data.has("oldMotes" + oldFileID[j] + "[]")) {
                if(moteAdded == 0) {
                    moteAdded = 1;
                    //add table for this mote type
                    table = document.createElement("table");
                    table.style.paddingBottom = "10px";
                    table.style.paddingTop = "10px";
                    table.style.borderBottom = "solid #37637f";
                    table.classList.add("table");
                    table.classList.add("table-hover");
                    table.classList.add("table-expandable");
                    table.classList.add("table-striped");
                    table.classList.add("text1");
                    table.style.width = "100%";
                    
                    var tableHeader = document.createElement("thead");
                    
                    var trHeader = document.createElement("tr");

                    var thFile = document.createElement("th");
                    var thMote = document.createElement("th");
                    var thDelete = document.createElement("th");
                    
                    var txtFile = document.createTextNode("File Name");
                    var txtMote = document.createTextNode("Number of Motes");
                    
                    thDelete.classList.add("table_edit_links");
                    
                    thFile.appendChild(txtFile);
                    thMote.appendChild(txtMote);
                    
                    trHeader.appendChild(thFile);
                    trHeader.appendChild(thMote);
                    trHeader.appendChild(thDelete);

                    tableHeader.appendChild(trHeader);
                    
                    tableHeader.style.textAlign = "left";
                    
                    var caption = document.createElement("caption");
                    caption.appendChild(document.createTextNode("Mote Type: " + data.get('moteTypeName' + i)));
                    caption.style.color = "black";
                    table.appendChild(caption);
                    
                    table.appendChild(tableHeader);
                    
                    tableBody = document.createElement("tbody");
                }
                
                //add this assosiated file to mote type table
                
                var trFile = document.createElement("tr");
                trFile.id = oldFileID[j] + "@oldFileRow";

                var tdFileName = document.createElement("td");
                tdFileName.style.width = "70%";
                var tdMote = document.createElement("td");

                var tdDelete = document.createElement("td");
                var tdDeleteDiv = document.createElement("div");
                jQuery(tdDeleteDiv).attr('title', "Delete Association");
                tdDeleteDiv.classList.add("table-delete");
                tdDeleteDiv.id= oldFileID[j] + "@tdDeleteDivOldFile";
                tdDeleteDiv.onclick = deleteAssociation;

                var txtFileName = document.createTextNode(oldFileName[j]);
                var motes = data.getAll("oldMotes" + oldFileID[j] + "[]");
                var txtMote = document.createTextNode(motes.length);

                tdFileName.appendChild(txtFileName);
                tdMote.appendChild(txtMote);

                tdDelete.appendChild(tdDeleteDiv);

                trFile.appendChild(tdFileName);
                trFile.appendChild(tdMote);
                trFile.appendChild(tdDelete);
                tableBody.appendChild(trFile);

            }
        }
        
        //new files
        for(var j = 0; j < data.get('numberOfFiles' + i); j++) {
            if(data.has("motes" + i + '' + j + "[]")) {
                if(moteAdded == 0) {
                    moteAdded = 1;
                    //add table for this mote type
                    table = document.createElement("table");
                    table.style.paddingBottom = "10px";
                    table.style.paddingTop = "10px";
                    //table.style.borderBottom = "solid #37637f";
                    table.classList.add("table");
                    table.classList.add("table-hover");
                    table.classList.add("table-expandable");
                    table.classList.add("table-striped");
                    table.classList.add("text1");
                    table.style.width = "100%";
                    
                    var tableHeader = document.createElement("thead");
                    
                    var trHeader = document.createElement("tr");

                    var thFile = document.createElement("th");
                    var thMote = document.createElement("th");
                    var thDelete = document.createElement("th");
                    
                    var txtFile = document.createTextNode("File Name");
                    var txtMote = document.createTextNode("Number of Motes");
                    
                    thDelete.classList.add("table_edit_links");
                    
                    thFile.appendChild(txtFile);
                    thMote.appendChild(txtMote);
                    
                    trHeader.appendChild(thFile);
                    trHeader.appendChild(thMote);
                    trHeader.appendChild(thDelete);

                    tableHeader.appendChild(trHeader);
                    
                    tableHeader.style.textAlign = "left";
                    
                    var caption = document.createElement("caption");
                    caption.appendChild(document.createTextNode("Mote Type: " + data.get('moteTypeName' + i)));
                    caption.style.color = "black";
                    table.appendChild(caption);
                    
                    table.appendChild(tableHeader);
                    
                    tableBody = document.createElement("tbody");
                }
                
                //add this assosiated file to mote type table
                
                var trFile = document.createElement("tr"); 
                trFile.id = i + "" + j + "@fileRow";

                var tdFileName = document.createElement("td");
                var tdMote = document.createElement("td");

                var tdDelete = document.createElement("td");
                var tdDeleteDiv = document.createElement("div");
                jQuery(tdDeleteDiv).attr('title', "Delete Association");
                tdDeleteDiv.classList.add("table-delete");
                tdDeleteDiv.id= i + "" + j + "@tdDeleteDiv";
                tdDeleteDiv.onclick = deleteAssociation;

                var txtFileName = document.createTextNode(data.get('fileName' + i + "" + j));
                var motes = data.getAll("motes" + i + "" + j + "[]");
                var txtMote = document.createTextNode(motes.length);

                tdFileName.appendChild(txtFileName);
                tdMote.appendChild(txtMote);

                tdDelete.appendChild(tdDeleteDiv);

                trFile.appendChild(tdFileName);
                trFile.appendChild(tdMote);
                trFile.appendChild(tdDelete);
                tableBody.appendChild(trFile);

            }
        }
        
        if(table != null) {
            table.appendChild(tableBody);
            associationTablesContainer.appendChild(table);
        }
    }
}

function deleteAssociation(){
    var fileID = this.id.split("@")[0];
    
    if(this.id.split("@")[1] == "tdDeleteDiv")
        data.delete("motes" + fileID + "[]");
    else
        data.delete("oldMotes" + fileID + "[]");
    
    refreshClustersMotes();
    refreshAssociationTable();
}

/*function scheduleLaterNow() {    
    $("#scheduleJob").toggle("fast");
}*/

/*function scheduleSoonTime() {
    if(document.getElementById("scheduleTime").checked == true)
        updateSchedule();
    $("#scheduledDateTime").toggle("fast");
    $("#scheduledDateTimeLabel").toggle("fast");
    $("#scheduledDateTimeNoteLabel").toggle("fast");
}*/

/*function updateSchedule() {
    //set date-time, min and max
    var tmLoc = new Date();
    tmLoc.setUTCMinutes(tmLoc.getUTCMinutes() + (8 * 60));
    var scheduledDateTime = document.getElementById("scheduledDateTime");
    //value, min = now, max=min+3days
    scheduledDateTime.value = tmLoc.toISOString().slice(0,16);
    scheduledDateTime.min = scheduledDateTime.value;
    var maxDate = tmLoc;
    maxDate.setDate(maxDate.getDate() + 2);
    scheduledDateTime.max = maxDate.toISOString().slice(0,16);
}*/

function spanErrorAddJobClick() {
    document.getElementById("addJobModal").style.display = "none";
}

function spanSuccessAddJobClick() {
    document.getElementById("addJobModal").style.display = "none";
    
    var associationJobDiv = document.getElementById("associationJobDiv");
    jQuery(associationJobDiv).toggle('slow');

    refreshJobs();
}

function scheduleNowJobAddJobClick(){
    document.getElementById("addJobModal").style.display = "none";
    
    var associationJobDiv = document.getElementById("associationJobDiv");
    jQuery(associationJobDiv).toggle('slow');
    
    jobID = addedJobID;
    scheduleJobFun();
}
