var userInfoChanged = 0;

function showUser(str)
{
    if (str.length == 0) {
        document.getElementById("userIDLabelFill").innerHTML = "Please, type the user's gmail id in the text field above!";
        document.getElementById("userAccountForm").style.display="none";
        document.getElementById("tableUsersInfo").style.display="none";
        return;
    } else {
        document.getElementById("tableUsersInfo").style.display="none";
        var userInfo = new FormData();
        userInfo.append('searchUserID', str.toLowerCase());

        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'php/showUser.php', true);
        xhr.send(userInfo);
        xhr.onload = function () {
            if (xhr.status === 200) {
                if(this.responseText == "not found"){
                    alert("No user in the databse with the  gmail id \"" + str + "\"");
                    document.getElementById("userAccountForm").style.display="none";
                }
                else{
                    userInfoChanged = 0;
                    
                    var myObj = JSON.parse(this.responseText);
                    
                    document.getElementById("userIDLabelFill").innerHTML = myObj.userID;
                    document.getElementById("quotatxt").value = myObj.quota;
                    document.getElementById('adminList').value = myObj.admin;
                    document.getElementById('allMotesList').value = myObj.allMotes;
                    document.getElementById("userNumberOfSubmissions").innerHTML = myObj.totalSubmissions;
                    document.getElementById("userNumberOfRunningTime").innerHTML = showQuota(myObj.runningTime) + " dd.hh:mm";
                    document.getElementById("userCreatedDate").innerHTML = myObj.create_date;
                    document.getElementById("userDetails").value = myObj.details;
                    
                    document.getElementById("userAccountForm").style.display="block";
                }
            }
        };
    }
}

function itemChanged() {
    userInfoChanged = 1;
}
