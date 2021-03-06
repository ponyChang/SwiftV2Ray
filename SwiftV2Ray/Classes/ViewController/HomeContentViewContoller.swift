//
//  HomeContentViewContoller.swift
//  SwiftV2Ray
//
//  Created by David.Dai on 2019/12/5.
//  Copyright © 2019 david. All rights reserved.
//

import UIKit
import NetworkExtension

class HomeContentViewContoller: UIViewController {
    var contentManger: HomeContentViewModel
    @IBOutlet weak var tableview: UITableView!
    
    init(contentManager model: HomeContentViewModel, nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        self.contentManger = model
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableview.register(UINib.init(nibName: "HomeContentControlCell", bundle: nil), forCellReuseIdentifier: "ControlCell")
        self.tableview.register(UINib.init(nibName: "HomeContentProxyCell", bundle: nil), forCellReuseIdentifier: "ProxyCell")
        NotificationCenter.default.addObserver(forName: NSNotification.Name.NEVPNStatusDidChange, object: nil, queue: OperationQueue.main, using: { notification in
            let connection = notification.object as? NEVPNConnection
            switch connection?.status {
                case .none: break
                case .some(.invalid): break
                case .some(.connecting): break
                case .some(.connected): break
                case .some(.reasserting): break
                case .some(.disconnecting): break
                case .some(_): break
            }
        })
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name.NEVPNStatusDidChange, object: nil)
    }
}

extension HomeContentViewContoller: UITableViewDataSource, UITableViewDelegate {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if section == 1 {
            return "服务节点"
        }
        
        return nil
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section == 0 {
            return 2
        }
        
        if section == 1 {
            return self.contentManger.serviceEndPoints.count
        }
        return 0
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // 开关服务
        if indexPath.section == 0 && indexPath.row == 0 {
            let cell = tableview.dequeueReusableCell(withIdentifier: "ControlCell", for: indexPath) as! HomeContentControlCell
            cell.switchClosure =  { [weak self] switchOn in
                self?.contentManger.serviceOpen = switchOn
                if switchOn == false {
                    self?.contentManger.closeService()
                    return
                }
                
                self?.contentManger.openService(completion: { (error) in
                    cell.switchOn((error != nil) ? false : true)
                })
            }
            return cell
        }
        
        // 选择代理模式
        if indexPath.section == 0 && indexPath.row == 1 {
            let cell = tableview.dequeueReusableCell(withIdentifier: "ProxyCell", for: indexPath) as! HomeContentProxyCell
            cell.modeChangeClosure = { segmentIndex in
                
            }
            return cell
        }
        
        // 服务节点
        
        
        return UITableViewCell()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableview.deselectRow(at: indexPath, animated: true)
        
    }
}
