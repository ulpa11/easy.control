const devices = document.querySelector('.devices')
const deviceList = [
    { id: 0, name: 'light', room: 'living room', state: 1 },
    { id: 1, name: 'fan', room: 'living room', state: 0 },
    { id: 2, name: 'AC', room: 'living room', state: 1 },
    { id: 3, name: 'lamp', room: 'living room', state: 0 }
]
let renderDevices = ''
deviceList.forEach(i => {
    if (i.state) {
        renderDevices += `
            <div class="device-tile-on" id="${i.id}">
                <h3>${i.name}</h3>
                <h4>${i.room}</h4>
                <div class="toggle-switch">
                    <div class="toggler"></div>
                </div>
            </div>
            `
    } else {
        renderDevices += `
            <div class="device-tile-off" id="${i.id}">
                <h3>${i.name}</h3>
                <h4>${i.room}</h4>
                <div class="toggle-switch">
                    <div class="toggler"></div>
                </div>
            </div>
            `
    }

});

devices.innerHTML = renderDevices

const toggleSwitch = document.querySelectorAll('.toggle-switch')

toggleSwitch.forEach(e => {
    e.addEventListener('click', function() {
        const num = (e.parentElement.id)
        const current = deviceList[num].state
        deviceList[num].state = !current
        const qwe = e.parentElement.classList
        console.log(qwe)
        console.log(deviceList[num].state)
        if (qwe.contains('device-tile-on')) {
            qwe.remove('device-tile-on')
            qwe.add('device-tile-off')
        } else {
            qwe.remove('device-tile-off')
            qwe.add('device-tile-on')
        }
    })
});